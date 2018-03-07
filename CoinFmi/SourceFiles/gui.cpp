#include <iostream>
#include "../Headers/gui.h"
#include "../Headers/commandhandler.h"
#include "../Headers/wallet.h"
using namespace std;

void printWelcomeMessage() {
	cout << "FMICoins [Version 0.0]\n(c) 2018 Dimitar Stoyanov, All rights reserved\n";
	cout << "For a list of commands type help\n\n";
}

void chooseOptionLoop() {
	cout << "Enter command> ";
	char * choiceChar = new char[100];
	cin.getline(choiceChar, 100);
	
	Choice choice = determineChoice(choiceChar);
	switch (choice) {
		case quit: exit(EXIT_SUCCESS); break;
		case help: printGeneralHelp(); break;
		case addwallet: addWallet(choiceChar); break;
		case walletinfo: walletInfo(choiceChar); break;
		case attractinvestors: printTopTen(); break;
		case makeorder: makeOrder(choiceChar); break;
		case invalid: chooseOptionLoop(); break;
	}
	delete choiceChar;
	chooseOptionLoop();
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
