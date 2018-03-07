#include "../Headers/gui.h"
using namespace std;

int main() {
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

	printWelcomeMessage();
	chooseOptionLoop();
	return 0;
}


