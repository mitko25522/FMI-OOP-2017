#pragma once

struct Wallet {
	char owner[256];
	unsigned id;
	double fiatMoney;
};

void addWallet(char*);
void extractName(char*, char*);
double extractFiatMoney(const char* input);
unsigned generateUniqueId();
bool idAlreadyExists(const long);
void saveWallet(Wallet);
void walletInfo(char *, const char* = "wallets.dat");
void printTopTen();
Wallet readWallet(size_t index);
size_t strl(const char*);
unsigned extractId(const char*);
void printWallet(Wallet);	