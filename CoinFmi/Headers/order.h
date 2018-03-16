#pragma once

struct Order {
	enum Type {
		SELL,
		BUY 
	};
	unsigned walletId;
	double fmiCoins;
};

void makeOrderBuy(const char*);
void makeOrderSell(const char*);