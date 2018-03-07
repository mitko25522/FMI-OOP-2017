#pragma once

struct Wallet {
	char owner[256];
	unsigned id;
	double fiatMoney;
};

void addWallet(char* choiceChar);
