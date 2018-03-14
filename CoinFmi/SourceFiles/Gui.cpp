#include "../Headers/gui.h"

void printWelcomeMessage() {
	std::cout << "FMICoins \n(c) 2018 Dimitar Stoyanov\n";
	std::cout << "For a list of commands type help\n\n";
}

void chooseOption() {
	std::cout << "Enter command> ";
	char * userInput = new char[100];
	std::cin.getline(userInput, 100);
	Choice choice = determineChoice(userInput);
	switch (choice) {
	case QUIT: delete[] userInput; exit(EXIT_SUCCESS); break;
	case HELP: printGeneralHelp(); break;
	case ADD_WALLET: createWallet(userInput); break;
	case WALLET_INFO: walletInfo(userInput); break;
	case ATTRACT_INVESTORS: printTopTen(); break;
	case TRANSACTION_LOG: printTransactionLog(); break;
	case WALLET_LIST: printWalletList(); break;
	case CLEAR_DATA: clearData(); break;
	//	case MAKE_ORDER: makeOrder(userInput); break;
	case INVALID: printInvalidInputError(userInput); break;
	}
	delete[] userInput;
}

void printGeneralHelp() {
	std::cout << "For more information on a specific command, type HELP command-name\n";
	std::cout << "add-wallet         Adds a new wallet to the database. \n";
	std::cout << "wallet-info        Displays info for a certain wallet. \n";
	std::cout << "quit               Exits the program saving current the changes made in the files.\n";
	std::cout << "make-order         Requests a payment to be made.\n";
	std::cout << "attract-investors  Prints the top ten richest users in the system.\n";
	std::cout << "transaction-log    Prints a log of the completed transactions.\n";
	std::cout << "wallet-list        Prints a list of existing wallets.\n";
	std::cout << "clear-data         Erases all data (WARNING this operation is not reversible).\n";
	std::cout << std::endl;
}

void printInvalidInputError(char* userInput) {
	std::cout << "'" << userInput << "' is not recognized as a supported command." << std::endl << std::endl;
}

void clearData(const char* wallets, const char* transactions) {
	std::ofstream InFile;
	InFile.open(wallets, std::ios::trunc);
	InFile.close();
	InFile.open(transactions, std::ios::trunc);
	InFile.close();
	std::cout << "All stored data has been cleared." << std::endl << std::endl;
}