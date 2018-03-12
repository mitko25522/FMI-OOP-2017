#include "../Headers/commandhandler.h"

Choice determineChoice(char* choiceStr) {
	convertToLowerCase(choiceStr);
	if (isQuit(choiceStr))
		return QUIT;
	else if (isHelp(choiceStr))
		return HELP;
	else if (isAddWallet(choiceStr))
		return ADD_WALLET;
	else if (isWalletInfo(choiceStr))
		return WALLET_INFO;
	else if (isAttractInvestors(choiceStr))
		return ATTRACT_INVESTORS;
	else if (isMakeOrder(choiceStr))
		return MAKE_ORDER;
	else
		return INVALID;
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
	const char* base = "help";
	for (int i = 0; base[i] != '\0'; i++) {
		if (input[i] != base[i]) {
			return false;
		}
	}
	return true;
}

bool isAddWallet(char* input) {
	const char* base = "add-wallet **";
	int observedIndex = 0;
	for (; base[observedIndex] != '\0'; observedIndex++) {
		if (input[observedIndex] != base[observedIndex]) {
			return false;
		}
	}

	for (; input[observedIndex] != '*'; observedIndex++) {
		if (!isNumber(input[observedIndex])) {
			return false;
		}
	}

	if (input[++observedIndex] != '*') {
		return false;
	}

	if (input[++observedIndex] != ' ') {
		return false;
	}

	if (input[++observedIndex] != '*') {
		return false;
	}

	if (input[(++observedIndex)++] != '*') {
		return false;
	}

	for (; input[observedIndex] != '*'; observedIndex++) {
		if (!isLetter(input[observedIndex]) && !isSpace(input[observedIndex])) {
			return false;
		}
	}

	if (input[++observedIndex] != '*') {
		return false;
	}

	if (input[++observedIndex] != '\0') {
		return false;
	}


	return true;
}

bool isWalletInfo(char* input) {
	return false;
}

bool isAttractInvestors(char* input) {
	return false;
}

bool isMakeOrder(char* input) {
	return false;
}

bool isNumber(char character) {
	if (character >= '0' && character <= '9') {
		return true;
	}
	else {
		return false;
	}
}

bool isLetter(char character) {
	if (character >= 'a' && character <= 'z') {
		return true;
	}
	else {
		return false;
	}
}

bool isSpace(char character) {
	return character == ' ';
}