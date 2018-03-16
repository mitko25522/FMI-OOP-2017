#pragma once

enum Choice
{
	INVALID,
	EMPTY,
	QUIT,
	HELP,
	ORDER_SELL,
	ORDER_BUY,
	ADD_WALLET,
	WALLET_INFO,
	ATTRACT_INVESTORS,
	TRANSACTION_LOG,
	WALLET_LIST,
	CLEAR_DATA
};

Choice determineChoice(char*);
void convertToLowerCase(char*);
bool isAddWallet(char*);
bool isWalletInfo(char*);
bool isNumber(char);
bool isLetter(char);
bool isSpace(char);
bool areEqual(char*, const char*);
bool isMakeOrder(const char*, const char*);
bool isEmpty(const char*);
