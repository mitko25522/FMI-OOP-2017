#include "../Headers/gui.h"
#include "../Headers/wallet.h"
#include "../Headers/commandhandler.h";
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
	printWelcomeMessage();
	while (true) {
		chooseOption();
	}
	/*char text[5];
	text[0] = 'h';
	text[1] = 'E';
	text[2] = 'l';
	text[3] = 'p';
	text[4] = '\0';
	char* pText = (char*)text;
	std::cout << isHelp(pText) << std::endl;*/
	return 0;
}


