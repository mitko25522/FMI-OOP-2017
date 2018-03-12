#pragma once

enum Choice
{
	INVALID,
	QUIT,
	HELP,
	ADD_WALLET,
	WALLET_INFO,
	ATTRACT_INVESTORS,
	MAKE_ORDER
};

Choice determineChoice(char*);
void convertToLowerCase(char*);
bool isAddWallet(char*);
bool isWalletInfo(char*);
bool isMakeOrder(char*);
bool isNumber(char);
bool isLetter(char);
bool isSpace(char);
bool areEqual(char*, const char*);