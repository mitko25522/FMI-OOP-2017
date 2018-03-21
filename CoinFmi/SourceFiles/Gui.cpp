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
		case ORDER_SELL: makeOrderSell(userInput); break;
		case ORDER_BUY: makeOrderBuy(userInput); break;
		case ADD_WALLET: createWallet(userInput); break;
		case WALLET_INFO: walletInfo(userInput); break;
		case ORDER_LIST: printActiveOrders(); break;
		case ATTRACT_INVESTORS: attractInvestors(); break;
		case TRANSACTION_LOG: printTransactionLog(); break;
		case WALLET_LIST: printWalletList(); break;
		case CLEAR_DATA: clearData(); break;
		case INVALID: printInvalidInputError(userInput); break;
		case EMPTY: break;
	}

	delete[] userInput;
}

void printGeneralHelp() {
	std::cout << "For more information on a specific command, type HELP command-name\n";
	std::cout << "add-wallet         Adds a new wallet to the database. \n";
	std::cout << "wallet-info        Displays info for a certain wallet. \n";
	std::cout << "quit               Exits the program saving current the changes made in the files.\n";
	std::cout << "make-order         Creates an order.\n";
	std::cout << "attract-investors  Prints the top ten richest users in the system.\n";
	std::cout << "transaction-log    Prints a log of the completed transactions.\n";
	std::cout << "wallet-list        Prints a list of existing wallets.\n";
	std::cout << "clear-data         Erases all data (WARNING this operation is not reversible).\n";
	std::cout << "order-list         Prints a list of all uncompleted orders.\n";
	std::cout << std::endl;
}

void printInvalidInputError(char* userInput) {
	std::cout << "'" << userInput << "' is not recognized as a supported command." << std::endl << std::endl;
}

//Opens the files in truncate mode clearing all previously stored data
void clearData(const char* wallets, const char* transactions, const char* orders) {
	std::ofstream InFile;
	InFile.open(wallets, std::ios::trunc);

	if (!InFile.good()) {
		std::cerr << "Error clearing " << wallets << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "'" << wallets << "' has been cleared." << std::endl;
	InFile.close();
	InFile.open(transactions, std::ios::trunc);

	if (!InFile.good()) {
		std::cerr << "Error clearing " << transactions << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "'" << transactions << "' has been cleared." << std::endl;
	InFile.close();
	InFile.open(orders, std::ios::trunc);

	if (!InFile.good()) {
		std::cerr << "Error clearing " << orders << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "'" << orders << "' has been cleared." << std::endl;
	InFile.close();
	std::cout << "All stored data has been cleared." << std::endl << std::endl;
}

//Needs to be used before doing anything else becouse at some points of
//the execution it is possible to request to read a file even though it
//doesn't exist. (makes sure all files are existent)
void createFiles(const char* wallets, const char* transactions, const char* orders) {
	std::ofstream InFile;
	InFile.open(wallets, std::ios::out | std::ios::app);

	if (!InFile.good()) {
		std::cerr << "Error loading " << wallets << std::endl;
		exit(EXIT_FAILURE);
	}

	InFile.close();
	InFile.open(transactions, std::ios::out | std::ios::app);

	if (!InFile.good()) {
		std::cerr << "Error loading " << transactions << std::endl;
		exit(EXIT_FAILURE);
	}


	InFile.close();
	InFile.open(orders, std::ios::out | std::ios::app);

	if (!InFile.good()) {
		std::cerr << "Error loading " << orders << std::endl;
		exit(EXIT_FAILURE);
	}

	InFile.close();
}