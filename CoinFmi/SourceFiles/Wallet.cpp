#include "../Headers/wallet.h"
#include <time.h>
#include <iostream>
#include <fstream>

void addWallet(char* choiceChar) {
	//takes input as "add-wallet **fiatMoney** **name**" template
	Wallet newWallet;
	newWallet.fiatMoney = extractFiatMoney(choiceChar);
	extractName(newWallet.owner, choiceChar);
	newWallet.id = generateUniqueId();
	saveWallet(newWallet);
}

void extractName(char* owner, char* input) {
	//moves name from input to owner
}

double extractFiatMoney(char* input) {
	double fiatMoney = 0;
	int index = 0;
	while (input[index + 1] != '*') {
		index++;
	}

	for (int j = 1; input[index] != '*'; j *= 10, index--) {
		fiatMoney += (input[index] - '0')*j;
	}
	return fiatMoney;
}

long int generateUniqueId() {
	srand(rand() ^ time(NULL));
	int tempArr[8];
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
	char newLineSymbol = '\n';
	std::ofstream OutFile;
	OutFile.open("wallets.dat", std::ios::out | std::ios::binary | std::ios::app);
	OutFile.write((char *)&wallet, sizeof(wallet));
	OutFile.close();
}

void walletInfo(char * userInput) {

}

void printTopTen() {

}

Wallet readWallet(size_t index) {
	std::ifstream inFile;
	inFile.open("wallets.dat", std::ios::binary | std::ios::in);
	Wallet wallet;
	Wallet* pWallet = &wallet;
	inFile.seekg(index * sizeof(Wallet));
	inFile.read((char*)pWallet, sizeof(Wallet));
	inFile.close();
	return wallet;
}