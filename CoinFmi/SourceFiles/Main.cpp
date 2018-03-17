#include "../Headers/gui.h"
#include "../Headers/wallet.h"
#include "../Headers/commandhandler.h"
#include "../Headers/transaction.h"
#include "../Headers/order.h"
#include <iostream>

int main() {
	printWelcomeMessage();

	while (true) {
		completeCompatibleOrders();
		chooseOption();
	}

	return 0;
}