#include "../Headers/commandhandler.h"

Choice determineChoice(char* choiceStr) {
	convertToLowerCase(choiceStr);
	if (areEqual(choiceStr, "quit"))
		return QUIT;
	else if (areEqual(choiceStr, "help"))
		return HELP;
	else if (isAddWallet(choiceStr))
		return ADD_WALLET;
	else if (isWalletInfo(choiceStr))
		return WALLET_INFO;
	else if (areEqual(choiceStr, "attract-investors"))
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
	const char* base = "wallet-info **";
	int observedIndex = 0;

	for (; base[observedIndex] != '\0'; observedIndex++) {
		if (input[observedIndex] != base[observedIndex]) {
			return false;
		}
	}

	for (int i = 0; i < 8; i++, observedIndex++) {
		if (!isNumber(input[observedIndex])) {
			return false;
		}
	}

	if (input[observedIndex++] != '*') {
		return false;
	}

	if (input[observedIndex++] != '*') {
		return false;
	}

	if (input[observedIndex] != '\0') {
		return false;
	}

	return true;
}

bool isMakeOrder(char* input) {
	return false;
}

bool isNumber(char character) {
	return (character >= '0' && character <= '9');
}

bool isLetter(char character) {
	return (character >= 'a' && character <= 'z');
}


bool isSpace(char character) {
	return character == ' ';
}

bool areEqual(char* input, const char* base) {
	for (int i = 0; base[i] != '\0'; i++) {
		if (input[i] != base[i]) {
			return false;
		}
		if (base[i + 1] == '\0' && input[i + 1] != '\0') {
			return false;
		}
	}
	return true;
}