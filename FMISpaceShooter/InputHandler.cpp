#include "InputHandler.h"
#include <windows.h>
#include <iostream>
#include "SpaceShooter.h"

Choice InputHandler::handleGameMenu() {
	do {
		if (GetAsyncKeyState(0x45)) {
			return Choice::EXIT;
		}
		
		if (GetAsyncKeyState(0x4E)) {
			return Choice::NEW_GAME;
		}
		 
		if (GetAsyncKeyState(0x4C)) {
			return Choice::LOAD_GAME;
		}
		
		if (GetAsyncKeyState(0x48)) {
			return Choice::HELP;
		}

		Sleep(50);
	} while (true);
}