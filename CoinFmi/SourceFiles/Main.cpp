#include "../Headers/gui.h"
#include "../Headers/wallet.h"
#include <iostream>
//int ch = 12345678;
//ofstream OutFile;
//OutFile.open("wallets.dat", ios::out | ios::binary | ios::app);
//OutFile.write((char*)&ch, sizeof(int));
//OutFile.close();

//int number;
//ifstream InFile;
//InFile.open("wallets.dat", ios::in | ios::binary);
//InFile.read((char*)&number, sizeof(int));
//cout << number;

int main() {
	/*printWelcomeMessage();
	chooseOptionLoop();*/

	//Wallet wallet;
	//wallet.id = 99999999;
	//for (int i = 0; i < 10; i++) {
	//	wallet.owner[i] = 'a' + i;
	//}
	//wallet.owner[10] = '\0';
	//wallet.fiatMoney = 500.3;
	//saveWallet(wallet);

	std::cout << idAlreadyExists(88888888) << std::endl;
	return 0;
}


