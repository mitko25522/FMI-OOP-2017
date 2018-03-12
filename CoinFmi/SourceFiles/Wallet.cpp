#include "../Headers/wallet.h"
#include <time.h>
#include <iostream>
#include <fstream>

void addWallet(char* choiceChar) {
	std::cout << "Adding wallet.." << std::endl;
	Wallet newWallet;
	newWallet.fiatMoney = extractFiatMoney(choiceChar);
	extractName(newWallet.owner, choiceChar);
	newWallet.id = generateUniqueId();
	saveWallet(newWallet);
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

//needs total recons
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

	//if (idAlreadyExists(id)) {
	//	generateUniqueId();
	//}

	std::cout << "Generated id: " << id << std::endl << std::endl;
	return id;
}

bool idAlreadyExists(const long generatedId) {

	std::ifstream InFile;
	InFile.open("wallets.dat", std::ios::in | std::ios::binary);
	do {
		int readId;
		InFile.read((char*)&readId, sizeof(int));
		if (readId == generatedId) {
			return true;
		}
		std::cout << InFile.tellg() << " " << readId << std::endl;
	} while (!InFile.eof());
	InFile.close();
	return false;
}

void saveWallet(Wallet wallet) {
	std::ofstream OutFile;
	OutFile.open("wallets.dat", std::ios::out | std::ios::binary | std::ios::app);
	OutFile.write((char *)&wallet, sizeof(wallet));
	OutFile.close();

}

void walletInfo(char * userInput, const char* fileName) {
	Wallet selectedWallet;
	selectedWallet.id = extractId(userInput);
	std::ifstream InFile;
	InFile.open("wallets.dat", std::ios::in | std::ios::binary);

	if (!InFile.is_open()) {
		std::cout << "Error reading " << fileName;
		exit(EXIT_FAILURE);
	}


	while (!InFile.eof()) {
		Wallet tempWallet;
		InFile.read((char*)&tempWallet, sizeof(Wallet));

		if (InFile.bad()) {
			std::cout << "Error reading " << fileName;
			exit(EXIT_FAILURE);
		}

		if (selectedWallet.id == tempWallet.id) {
			selectedWallet = tempWallet;
			printWallet(selectedWallet);
			return;
		}

		if (InFile.eof()) {
			std::cout << "No such wallet found in " << fileName;
		}
	}
}

void printTopTen() {

}

Wallet readWallet(size_t index) {
	std::ifstream inFile;
	inFile.open("wallets.dat", std::ios::in | std::ios::binary);
	Wallet wallet;
	Wallet* pWallet = &wallet;
	inFile.seekg(index * sizeof(Wallet));
	inFile.read((char*)pWallet, sizeof(Wallet));
	inFile.close();
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