#pragma once

struct Wallet {
	char owner[256];
	unsigned id;
	double fiatMoney;
};

void addWallet(char*);
void extractName(char*, char*);
double extractFiatMoney(char* input);
long int generateUniqueId();
bool idAlreadyExists(const long);	
void saveWallet(Wallet);
void walletInfo(char *);
void printTopTen();
Wallet readWallet(size_t index);	