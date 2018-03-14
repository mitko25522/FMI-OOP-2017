#include "../Headers/wallet.h"
#include "../Headers/transaction.h"

void createWallet(char* choiceChar) {
	Wallet newWallet;
	newWallet.fiatMoney = extractFiatMoney(choiceChar);
	if (didNotInvest(newWallet)) {
		std::cout << "No money invested. Cannot create wallet." << std::endl << std::endl;
		return;
	}
	extractName(newWallet.owner, choiceChar);
	std::cout << "Adding wallet.." << std::endl;
	newWallet.id = generateUniqueId();
	saveWallet(newWallet);
	Transaction transaction = createTransaction(newWallet.fiatMoney / FMI_COIN_RATE, SYSTEM_ID, newWallet.id);
	saveTransaction(transaction);
}

void extractName(char* to, char* from) {
	size_t len = strl(from);
	int index = len - 3;
	while (from[index - 1] != '*') {
		index--;
	}

	for (int i = 0; from[index] != '*'; i++, index++) {
		to[i] = from[index];
		if (from[index + 1] == '*') {
			to[i + 1] = '\0';
		}
	}

}

double extractFiatMoney(const char * input) {
	double fiatMoney = 0;
	int index = 13;
	while (input[index + 1] != '*') {
		index++;
	}

	for (int j = 1; input[index] != '*'; j *= 10, index--) {
		fiatMoney += (input[index] - '0')*j;
	}
	return fiatMoney;
}

//needs total reconstruction
unsigned generateUniqueId() {
	srand(rand() ^ time(NULL));
	unsigned tempArr[8];
	tempArr[0] = (rand() % 8) + 1;

	for (int i = 1; i < 8; i++) {
		tempArr[i] = rand() % 10;
	}

	long int id = 0;
	for (int i = 7, j = 1; i >= 0; i--, j *= 10) {
		id += tempArr[i] * j;
	}

	if (idAlreadyExists(id)) {
		generateUniqueId();
	}

	std::cout << "Generated id: " << id << std::endl << std::endl;
	return id;
}

bool idAlreadyExists(unsigned generatedId, const char* fileName) {
	std::ifstream InFile;
	InFile.open("wallets.dat", std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}

		if (generatedId == tempWallet.id) {
			return true;
		}
	}

	InFile.close();
	return false;
}

void saveWallet(Wallet wallet, const char* fileName) {
	std::ofstream OutFile;
	OutFile.open(fileName, std::ios::out | std::ios::binary | std::ios::app);

	if (OutFile.is_open()) {
		OutFile.write((char *)&wallet, sizeof(wallet));
		if (OutFile.bad()) {
			std::cerr << "Error writing in " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	else {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	OutFile.close();
}

void walletInfo(char * userInput, const char* fileName) {
	Wallet selectedWallet;
	selectedWallet.id = extractId(userInput);
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}


	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}

		if (selectedWallet.id == tempWallet.id) {
			selectedWallet = tempWallet;
			printWallet(selectedWallet);
			InFile.close();
			return;
		}

		if (InFile.eof()) {
			std::cout << "No such wallet found in " << fileName << std::endl << std::endl;
			InFile.close();
		}
	}
}

void printTopTen() {
	int count = countOfTopWallets();

	if (count == 0) {
		std::cout << "No wallets exist in the database" << std::endl << std::endl;
		return;
	}

	Wallet* wallets = new Wallet[count];
	wallets = getTopWallets(count);
	for (int i = 0; i < 10; i++) {
		if (i >= count) {
			std::cout << i + 1 << ". N/A" << std::endl;
			continue;
		}
		std::cout << i + 1 << ". " << wallets[i].id << " | ";
		printStr(wallets[i].owner);
		std::cout << " | " << wallets[i].fiatMoney << std::endl;
	}
	std::cout << std::endl;

	delete[] wallets;
}

//potentially dangerous, needs fixing currently not suitable for use
Wallet readWallet(size_t index) {
	std::ifstream InFile;
	InFile.open("wallets.dat", std::ios::in | std::ios::binary);
	Wallet wallet;
	Wallet* pWallet = &wallet;
	InFile.seekg(index * sizeof(Wallet));
	InFile.read((char*)pWallet, sizeof(Wallet));
	InFile.close();
	return wallet;
}

size_t strl(const char* str) {
	size_t len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

unsigned extractId(const char* input) {
	unsigned id = 0;
	int index = 14;

	while (input[index + 1] != '*') {
		index++;
	}

	for (int j = 1; input[index] != '*'; j *= 10, index--) {
		id += (input[index] - '0')*j;
	}

	return id;
}

void printWallet(Wallet wallet) {
	std::cout << "Wallet id: " << wallet.id << std::endl;
	std::cout << "Owner  name: ";
	for (int i = 0; wallet.owner[i] != '\0'; i++) {
		std::cout << wallet.owner[i];
	}
	std::cout << std::endl << "Fiat money: " << wallet.fiatMoney << std::endl << std::endl;
}

uint8_t countOfTopWallets(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	uint8_t count = 0;
	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}

		if (!InFile.eof()) {
			count++;
		}

		if (count >= 10) {
			return 10;
		}
	}

	InFile.close();
	return count;
}


Wallet* getTopWallets(uint8_t count, const char* fileName) {
	Wallet* topWallets = new Wallet[count];
	topWallets[0] = getRichestWallet();
	for (int i = 1; i < count; i++) {
		topWallets[i] = getNextRichestWallet(topWallets[i - 1].fiatMoney);
	}
	return topWallets;
}

Wallet getRichestWallet(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	Wallet richestWallet;
	InFile.read((char*)&richestWallet, sizeof(Wallet));

	if (InFile.bad()) {
		std::cerr << "Error reading " << fileName << std::endl;
		InFile.close();
		exit(EXIT_FAILURE);
	}

	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}

		if (tempWallet.fiatMoney > richestWallet.fiatMoney) {
			richestWallet = tempWallet;
		}
	}

	InFile.close();
	return richestWallet;
}

Wallet getNextRichestWallet(double previousRichestFiatMoney, const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	Wallet nextRichestWallet;
	nextRichestWallet.fiatMoney = 0;
	double currentMaxMoney = 0;

	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName;
		}

		if (tempWallet.fiatMoney == previousRichestFiatMoney) {
			continue;
		}

		if (tempWallet.fiatMoney > currentMaxMoney && tempWallet.fiatMoney < previousRichestFiatMoney) {
			currentMaxMoney = tempWallet.fiatMoney;
		}

		if (currentMaxMoney > nextRichestWallet.fiatMoney) {
			nextRichestWallet = tempWallet;
		}
	}

	InFile.close();
	return nextRichestWallet;
}

void printStr(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		std::cout << str[i];
	}
}

bool didNotInvest(Wallet wallet) {
	return !wallet.fiatMoney;
}
