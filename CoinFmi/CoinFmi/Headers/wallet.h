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
double extractInteger(const char*, int);
void extractName(char*, char*);
unsigned generateUniqueId();
bool idExists(unsigned, const char* = "wallets.dat");
void saveWallet(Wallet, const char* = "wallets.dat");
void walletInfo(char *, const char* = "wallets.dat");
void attractInvestors();
Wallet readWallet(unsigned, const char* = "wallets.dat");
size_t strl(const char*);
unsigned extractId(const char*);
void printWallet(Wallet);
uint8_t countOfTopWallets(const char* = "wallets.dat");
void getTopWallets(Wallet*, uint8_t, const char* = "wallets.dat");
Wallet getRichestWallet(const char* = "wallets.dat");
Wallet getNextRichestWallet(double, const char* = "wallets.dat");
void printStr(char*);
bool didNotInvest(double);
void printWalletList(const char* = "wallets.dat");
void compactPrintWallet(Wallet);
int findWalletPos(unsigned, const char* = "wallets.dat");
void printTopWallets(Wallet*, uint8_t);