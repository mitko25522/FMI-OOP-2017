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

	if (alreadyExists(id)) {
		generateUniqueId();
	}

	return id;
}

bool alreadyExists(const long) {
	//needs work
	return true;
}

void saveWallet(Wallet wallet) {
	//in progress
	char newLineSymbol = '\n';
	std::ofstream OutFile;
	OutFile.open("wallets.dat", std::ios::out | std::ios::binary | std::ios::app);
	OutFile.write((char *)&wallet.id, sizeof(long));
	OutFile.write((char *)&wallet.fiatMoney, sizeof(double));
	OutFile.write(wallet.owner, strlen(wallet.owner));
	OutFile.write(&newLineSymbol,1);
	OutFile.close();
}