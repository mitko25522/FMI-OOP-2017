#include <iostream>
#include "../Headers/gui.h"
#include "../Headers/commandhandler.h"
#include "../Headers/wallet.h"
using namespace std;

void printWelcomeMessage() {
	cout << "FMICoins \n(c) 2018 Dimitar Stoyanov\n";
	cout << "For a list of commands type help\n\n";
}

void chooseOption() {
	cout << "Enter command> ";
	char * userInput = new char[100];
	cin.getline(userInput, 100);
	Choice choice = determineChoice(userInput);
	switch (choice) {
		case QUIT: exit(EXIT_SUCCESS); break;
		case HELP: printGeneralHelp(); break;
		case ADD_WALLET: addWallet(userInput); break;
		case WALLET_INFO: walletInfo(userInput); break;
		case ATTRACT_INVESTORS: printTopTen(); break;
	//	case MAKE_ORDER: makeOrder(userInput); break;
		case INVALID: break;
	}
	delete[] userInput;
}

void printGeneralHelp() {
	cout << "For more information on a specific command, type HELP command-name\n";
	cout << "add-wallet         Adds a new wallet to the database. \n";
	cout << "wallet-info        Displays info for a certain wallet. \n";
	cout << "quit               Exits the program saving current the changes made in the files.\n";
	cout << "make-order         Requests a payment to be made.\n";
	cout << "attract-investors  Prints the top ten richest users in the system.\n";
	cout << endl;
}
