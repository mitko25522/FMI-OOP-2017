#pragma once
#include <time.h>
#include <fstream>
#include <iostream>

#define SYSTEM_ID 4294967295
#define FMI_COIN_RATE 375

struct Transaction {
	double fmiCoins;
	unsigned senderId;
	unsigned receiverId;
	long long time;
};

Transaction createTransaction(double, unsigned, unsigned, time_t = time(0));
void saveTransaction(Transaction, const char* = "transactions.dat");
double calculateFmiCoins(Wallet, const char* = "transactions.dat");
bool isSender(Wallet, Transaction);
bool isReceiver(Wallet, Transaction);
double extractFmiCoins(Transaction);
void printTransaction(Transaction);
void printTransactionLog(const char* = "transactions.dat");