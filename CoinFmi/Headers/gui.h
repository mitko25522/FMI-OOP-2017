#pragma once

#include <iostream>
#include "../Headers/commandhandler.h"
#include "../Headers/wallet.h"
#include "../Headers/transaction.h"
#include "../Headers/order.h"

void printWelcomeMessage();
void chooseOption();
void printGeneralHelp();
void printInvalidInputError(char*);
void clearData(const char* = "wallets.dat", const char* = "transactions.dat", const char* = "orders.dat");
void createFiles(const char* = "wallets.dat", const char* = "transactions.dat", const char* = "orders.dat");