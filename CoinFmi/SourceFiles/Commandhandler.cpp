#include "../Headers/commandhandler.h"

Choice determineChoice(char* choiceStr) {
	convertToLowerCase(choiceStr);
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

void convertToLowerCase(char* input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if ('A' <= input[i] && input[i] <= 'Z') {
			input[i] = char(((int)input[i]) + 32);
		}
	}
}

bool isQuit(char* input) {
	convertToLowerCase(input);
	const char* base = "quit";
	for (int i = 0; base[i] != '\0'; i++) {
		if (input[i] != base[i]) {
			return false;
		}
	}
	return true;
}

bool isHelp(char* input) {
	convertToLowerCase(input);
	const char* base = "help";
	for (int i = 0; base[i] != '\0'; i++) {
		if (input[i] != base[i]) {
			return false;
		}
	}
	return true;
}

bool isAddWallet(char* input) {
	convertToLowerCase(input);
	return false;
}

bool isWalletInfo(char* input) {
	convertToLowerCase(input);
	return false;
}

bool isAttractInvestors(char* input) {
	convertToLowerCase(input);
	return false;
}

bool isMakeOrder(char* input) {
	convertToLowerCase(input);
	return false;
}