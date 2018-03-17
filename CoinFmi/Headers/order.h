#pragma once


struct Order {
	enum Type {
		SELL,
		BUY
	} type;
	unsigned walletId;
	double fmiCoins;
};

void makeOrderBuy(const char*);
void makeOrderSell(const char*);
double extractFmiCoins(const char*);
bool dotExists(const char*);
double extractDouble(const char*);
int getDotIndex(const char*);
void writeOrder(Order, const char* = "orders.dat");
bool hasEnoughCoins(unsigned, double);
bool hasEnoughFiatMoney(unsigned, double);
void printActiveOrders(const char* = "orders.dat");
void compactPrintOrder(Order);
void completeCompatibleOrders(const char* = "orders.dat");
bool compatibleOrdersExist(const char* = "orders.dat");
int countOrders(const char* = "orders.dat");
bool areCompatible(Order, Order);
bool isSale(Order);
bool isPurchase(Order);