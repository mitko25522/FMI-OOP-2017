#include "commandhandler.h"

Choice determineChoice(char* choiceStr) {
	if (isQuit(choiceStr))
		return quit;
	else if (isHelp(choiceStr))
		return help;
	else if (isAddWallet(choiceStr))
		return addwallet;
	else if (isWalletInfo(choiceStr))
		return walletinfo;
	else if (isAttractInvestors(choiceStr))
		return attractinvestors;
	else if (isMakeOrder(choiceStr))
		return makeorder;
	else 
		return invalid;
}