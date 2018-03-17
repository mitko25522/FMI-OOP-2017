#include "../Headers/wallet.h"
#include "../Headers/transaction.h"

Transaction createTransaction(double fmiCoins, unsigned senderId, unsigned receiverId, time_t timeOfTransaction) {
	Transaction newTransaction;
	newTransaction.fmiCoins = fmiCoins;
	newTransaction.senderId = senderId;
	newTransaction.receiverId = receiverId;
	newTransaction.time = timeOfTransaction;
	return newTransaction;
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

	OutFile.close();
}

double calculateFmiCoins(Wallet wallet, const char* fileName) {
	std::ifstream InFile;
	InFile.open(fileName, std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cerr << "Error reading " << fileName << std::endl;
		exit(EXIT_SUCCESS);
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
		exit(EXIT_SUCCESS);
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