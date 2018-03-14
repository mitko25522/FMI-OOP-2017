#pragma once

#include <stdint.h>
#include <time.h>
#include <iostream>
#include <fstream>

struct Wallet {
	char owner[256];
	unsigned id;
	double fiatMoney;
};

void createWallet(char*);
void extractName(char*, char*);
double extractFiatMoney(const char*);
unsigned generateUniqueId();
bool idAlreadyExists(unsigned, const char* = "wallets.dat");
void saveWallet(Wallet, const char* = "wallets.dat");
void walletInfo(char *, const char* = "wallets.dat");
void printTopTen();
Wallet readWallet(size_t);
size_t strl(const char*);
unsigned extractId(const char*);
void printWallet(Wallet);
uint8_t countOfTopWallets(const char* = "wallets.dat");
void getTopWallets(Wallet*, uint8_t, const char* = "wallets.dat");
Wallet getRichestWallet(const char* = "wallets.dat");
Wallet getNextRichestWallet(double, const char* = "wallets.dat");
void printStr(char*);
bool didNotInvest(Wallet);