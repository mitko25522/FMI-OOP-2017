#pragma once

enum Choice
{
	invalid,
	quit,
	help,
	addwallet,
	walletinfo,
	attractinvestors,
	makeorder
};

Choice determineChoice(char*);
void convertToLowerCase(char*);
bool isQuit(char*);
bool isHelp(char*);
bool isAddWallet(char*);
bool isWalletInfo(char*);
bool isAttractInvestors(char*);
bool isMakeOrder(char*);