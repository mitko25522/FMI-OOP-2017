#include "../Headers/wallet.h"
#include "../Headers/transaction.h"

void createTransaction(double fmiCoins, unsigned senderId, unsigned receiverId, time_t timeOfTransaction) {
	Transaction newTransaction;
	newTransaction.fmiCoins = fmiCoins;
	newTransaction.senderId = senderId;
	newTransaction.receiverId = receiverId;

	if (senderId != SYSTEM_ID) {
	//	modifyFiatMoney(newTransaction.receiverId, newTransaction.fmiCoins * FMI_COIN_RATE);
	}

	newTransaction.time = timeOfTransaction;
	saveTransaction(newTransaction);
}

void modifyFiatMoney(unsigned walletId, double fiatMoneyToDeduct, const char* fileName) {
	Wallet walletToModify = readWallet(walletId);
	walletToModify.fiatMoney -= fiatMoneyToDeduct;
	int walletPos = findWalletPos(walletId);
	std::ofstream OutFile;
	OutFile.open(fileName);

	if (!OutFile.is_open()) {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	OutFile.seekp(walletPos);
	OutFile.write((const char*)&walletToModify, sizeof(Wallet));

	if (OutFile.bad()) {
		std::cerr << "Error writing in " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	OutFile.close();
}

void saveTransaction(Transaction transaction, const char* fileName) {
	std::ofstream OutFile;
	OutFile.open(fileName, std::ios::out | std::ios::binary | std::ios::app);
	if (OutFile.is_open()) {
		OutFile.write((char *)&transaction, sizeof(transaction));
		if (OutFile.bad()) {
			std::cerr << "Error writing in " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Transaction created:\nFrom: " << transaction.senderId << " | To: " << transaction.receiverId << " | Time: " << transaction.time << " | Fmi coins: " << transaction.fmiCoins << std::endl << std::endl;
	OutFile.close();
}

//Calculates fmi coins taking into account all transactions that affect the specified wallet
double calculateFmiCoins(Wallet wallet, const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error opening " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	double fmiCoins = 0;
	while (!InFile.eof()) {
		Transaction tempTransaction;
		InFile.read((char*)&tempTransaction, sizeof(Transaction));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
		else if (InFile.eof()) {
			break;
		}

		if (isSender(wallet, tempTransaction)) {
			fmiCoins -= extractTransactionFmiCoins(tempTransaction);
		}
		else if (isReceiver(wallet, tempTransaction)) {
			fmiCoins += extractTransactionFmiCoins(tempTransaction);
		}

	}
	return fmiCoins;
}

bool isSender(Wallet wallet, Transaction transaction) {
	return wallet.id == transaction.senderId;
}

bool isReceiver(Wallet wallet, Transaction transaction) {
	return wallet.id == transaction.receiverId;
}

double extractTransactionFmiCoins(Transaction transaction) {
	return transaction.fmiCoins;
}

void printTransactionLog(const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	Transaction tempTransaction;
	InFile.read((char*)&tempTransaction, sizeof(Transaction));

	if (InFile.bad()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (InFile.eof()) {
		std::cout << "No transactions stored in '" << fileName << "'" << std::endl << std::endl;
		return;
	}

	printTransaction(tempTransaction);

	while (!InFile.eof()) {
		InFile.read((char*)&tempTransaction, sizeof(Transaction));

		if (InFile.bad()) {
			std::cerr << "Error reading " << fileName << std::endl;
			exit(EXIT_FAILURE);
		}
		else if (InFile.eof()) {
			std::cout << std::endl;
			break;
		}
		printTransaction(tempTransaction);
	}
}

void printTransaction(Transaction transaction) {
	std::cout << "From: " << transaction.senderId << " | To: " << transaction.receiverId << " | Time: " << transaction.time << " | Amount: " << transaction.fmiCoins << std::endl;
}