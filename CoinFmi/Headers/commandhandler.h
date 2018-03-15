#pragma once

enum Choice
{
	INVALID,
	QUIT,
	HELP,
	ADD_WALLET,
	WALLET_INFO,
	ATTRACT_INVESTORS,
	TRANSACTION_LOG,
	WALLET_LIST,
	CLEAR_DATA,
	MAKE_ORDER
};

Choice determineChoice(char*);
void convertToLowerCase(char*);
bool isAddWallet(char*);
bool isWalletInfo(char*);
bool isMakeOrder(char*);//needs work
bool isNumber(char);
bool isLetter(char);
bool isSpace(char);
bool areEqual(char*, const char*);