#include "../Headers/commandhandler.h"
#include "../Headers/order.h"

Choice determineChoice(char* choiceStr) {
	convertToLowerCase(choiceStr);
	if (areEqual(choiceStr, "quit"))
		return QUIT;
	else if (areEqual(choiceStr, "help"))
		return HELP;
	else if (isMakeOrder(choiceStr, "sell"))
		return ORDER_SELL;
	else if (isMakeOrder(choiceStr, "buy"))
		return ORDER_BUY;
	else if (isAddWallet(choiceStr))
		return ADD_WALLET;
	else if (isWalletInfo(choiceStr))
		return WALLET_INFO;
	else if (areEqual(choiceStr, "order-list"))
		return ORDER_LIST;
	else if (areEqual(choiceStr, "attract-investors"))
		return ATTRACT_INVESTORS;
	else if (areEqual(choiceStr, "transaction-log"))
		return TRANSACTION_LOG;
	else if (areEqual(choiceStr, "wallet-list"))
		return WALLET_LIST;
	else if (areEqual(choiceStr, "clear-data"))
		return CLEAR_DATA;
	else if (isEmpty(choiceStr))
		return EMPTY;
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
	const char* base = "add-wallet ";
	int observedIndex = 0;

	for (; base[observedIndex] != '\0'; observedIndex++) {
		if (input[observedIndex] != base[observedIndex]) {
			return false;
		}
	}

	for (; input[observedIndex] != ' '; observedIndex++) {
		if (!isNumber(input[observedIndex])) {
			return false;
		}
	}

	for (; input[observedIndex] != '\0'; observedIndex++) {
		if (!isLetter(input[observedIndex]) && !isSpace(input[observedIndex])) {
			return false;
		}
	}

	return true;
}

bool isWalletInfo(char* input) {
	const char* base = "wallet-info ";
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

	if (input[observedIndex] != '\0') {
		return false;
	}

	return true;
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

bool isMakeOrder(const char* input, const char* type) {
	const char* base = "make-order ";

	int index = 0;

	for (; base[index] != '\0'; index++) {
		if (input[index] != base[index]) {
			return false;
		}
	}

	for (int i=0; type[i] != '\0'; index++, i++) {
		if (input[index] != type[i]) {
			return false;
		}
	}

	if (input[index++] != ' ') {
		return false;
	}

	int dotCount = 0;

	if (!isNumber(input[index])) {
		return false;
	}

	index++;

	for (; input[index] != ' '; index++) {
		if (input[index] != '.' && !isNumber(input[index])) {
			return false;
		}

		if (input[index] == '.') {
			dotCount++;
		}

		if (dotCount >= 2) {
			return false;
		}
	}

	index++;

	for (int i = 0; i < 8; i++) {
		if (!isNumber(input[index++])) {
			return false;
		}
	}

	if (input[index] != '\0') {
		return false;
	}

	if (dotExists(input)) {
		index = getDotIndex(input);
	}

	if (input[++index] == ' ') {
		return false;
	}

	return true;
}

bool isEmpty(const char* input) {
	return input[0] == '\0';
}