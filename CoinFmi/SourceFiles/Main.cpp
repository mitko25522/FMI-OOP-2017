#include "../Headers/gui.h"
#include "../Headers/wallet.h"
#include "../Headers/commandhandler.h";
#include <iostream>

int main() {
	printWelcomeMessage();
	while (true) {
		chooseOption();
	}	
	return 0;
}


