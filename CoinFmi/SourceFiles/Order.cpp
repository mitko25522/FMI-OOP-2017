#include "../Headers/order.h"
#include "../Headers/wallet.h"
#include "../Headers/transaction.h"
#include "../Headers/commandhandler.h"

void makeOrderBuy(const char* input) {
	std::cout << "Initiating order.." << std::endl;
	Order order;
	order.type = order.BUY;
	order.walletId = extractId(input);

	if (!idExists(order.walletId)) {
		std::cout << "No such id in the database.. Canceling order" << std::endl << std::endl;
		return;
	}
	else {
		order.fmiCoins = extractFmiCoins(input);
	}

	if (order.fmiCoins == 0) {
		std::cout << "Purchase of 0 fmi coins can not be completed" << std::endl << std::endl;
		return;
	}
	if (!hasEnoughFiatMoney(order.walletId, order.fmiCoins)) {
		std::cout << "Wallet does not have enough fiat money.. Canceling order" << std::endl << std::endl;
		return;
	}

	writeOrder(order);
}

void makeOrderSell(const char* input) {
	std::cout << "Initiating order.." << std::endl;
	Order order;
	order.type = order.SELL;
	order.walletId = extractId(input);

	if (!idExists(order.walletId)) {
		std::cout << "No such id in the database.. Canceling order" << std::endl << std::endl;
		return;
	}
	else {
		order.fmiCoins = extractFmiCoins(input);
	}

	if (order.fmiCoins == 0) {
		std::cout << "Sale of 0 fmi coins can not be completed.. Canceling order" << std::endl << std::endl;
		return;
	}

	if (!hasEnoughCoins(order.walletId, order.fmiCoins)) {
		std::cout << "Wallet does not have enough fmi coins.. Canceling order" << std::endl << std::endl;
		return;
	}

	writeOrder(order);
}

double extractFmiCoins(const char* input) {
	if (dotExists(input)) {
		return extractDouble(input);
	}
	else {
		return extractInteger(input, 16);
	}
}

bool dotExists(const char* input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '.') {
			return true;
		}
	}
	return false;
}

double extractDouble(const char* input) {
	int index = getDotIndex(input) - 1;

	while (isNumber(input[index])) {
		index--;
	}

	index++;

	double number = 0;
	number = toNum(input, index);
	return number;
}

//Use only if you are sure the string has a dot in it
int getDotIndex(const char* input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '.') {
			return i;
		}
	}
}

bool hasEnoughCoins(unsigned id, double fmiCoins) {
	Wallet seller = readWallet(id);
	if (calculateFmiCoins(seller) >= fmiCoins) {
		return true;
	}
	else {
		return false;
	}
}

bool hasEnoughFiatMoney(unsigned walletId, double fmiCoins) {
	double orderFiatMoney = fmiCoins * FMI_COIN_RATE;
	Wallet wallet = readWallet(walletId);
	return orderFiatMoney <= wallet.fiatMoney;
}

void writeOrder(Order order, const char* fileName) {
	std::cout << "Saving order details to " << fileName << std::endl;
	std::ofstream OutFile;
	OutFile.open(fileName, std::ios::out | std::ios::binary | std::ios::app);

	if (OutFile.is_open()) {
		OutFile.write((char*)&order, sizeof(Order));
		if (OutFile.bad()) {
			std::cerr << "Error writing in " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Done" << std::endl << std::endl;
	OutFile.close();
}

double toNum(const char* x, int index = 0) {
	double total = 0, number;
	int modifier = 10;
	bool decimal = false;
	while (x[index] && x[index] != ' ') {
		number = x[index] - '0';
		if (decimal) {
			number = number / modifier;
			modifier = modifier * 10;
		}
		else if (!decimal && (x[index] >= '0' && x[index] <= '9')) {
			total = total * 10;
		}

		if (x[index] == '.') {
			decimal = true;
		}
		else {
			total += number;
		}

		index++;
	}
	return total;
}

void printActiveOrders(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	Order tempOrder;
	InFile.read((char*)&tempOrder, sizeof(Order));

	if (InFile.bad()) {
		std::cerr << "Error reading " << fileName << std::endl;
		InFile.close();
		exit(EXIT_FAILURE);
	}
	else if (InFile.eof()) {
		std::cout << "No orders stored in '" << fileName << "'" << std::endl << std::endl;
		InFile.close();
		return;
	}

	compactPrintOrder(tempOrder);

	while (!InFile.eof()) {
		InFile.read((char*)&tempOrder, sizeof(Order));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
		else if (InFile.eof()) {
			std::cout << std::endl;
			break;
		}

		compactPrintOrder(tempOrder);
	}
	InFile.close();
}

void compactPrintOrder(Order order) {
	std::cout << "Originator id: " << order.walletId << " | Type: ";

	if (order.type == order.SELL) {
		std::cout << "sell";
	}
	else {
		std::cout << "buy";
	}

	std::cout << " | Amount: " << order.fmiCoins << std::endl;
}

void completeCompatibleOrders(const char* fileName) {
	//work here make one transaction between existing compatible orders

}

bool compatibleOrdersExist(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_SUCCESS);
	}

	if (countOrders() < 2) {
		return false;
	}


	while (!InFile.eof()) {
		Order currentOrder;
		InFile.read((char*)&currentOrder, sizeof(Order));

		if (InFile.eof()) {
			break;
		}

		int currentPos = InFile.tellg();

		while (!InFile.eof()) {
			Order tempOrder;
			InFile.read((char*)&tempOrder, sizeof(Order));
			if (areCompatible(currentOrder, tempOrder)) {
				return true;
			}
			if (areCompatible(tempOrder, currentOrder)) {
				return true;
			}
		}
	}

	InFile.close();
	return false;
}

int countOrders(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_SUCCESS);
	}

	int orderCount = 0;

	while (!InFile.eof()) {
		Order tempOrder;
		InFile.read((char*)&tempOrder, sizeof(Order));
		if (!InFile.eof()) {
			orderCount++;
		}
	}

	return orderCount;
}

bool areCompatible(Order orderOne, Order orderTwo) {
	if (orderOne.walletId == orderTwo.walletId) {
		return false;
	}

	if (isSale(orderOne) && isPurchase(orderTwo)) {
		if (orderOne.fmiCoins >= orderTwo.fmiCoins) {
			return true;
		}
	}
	else if (isPurchase(orderOne) && isSale(orderTwo)) {
		if (orderOne.fmiCoins <= orderTwo.fmiCoins) {
			return true;
		}
	}
	return false;
}

bool isSale(Order order) {
	return order.type == order.SELL;
}

bool isPurchase(Order order) {
	return order.type == order.BUY;
}