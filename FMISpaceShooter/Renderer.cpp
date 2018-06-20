#include "Renderer.h"
#include <windows.h>

void Renderer::printTextFmi() {
	std::cout << "			  ______ __  __ _____							\n";
	std::cout << "			 |  ____|  \\/  |_   _|							\n";
	std::cout << "			 | |__  | \\  / | | |							\n";
	std::cout << "			 |  __| | |\\/| | | |							\n";
	std::cout << "			 | |    | |  | |_| |_							\n";
	std::cout << "			 |_|____|_|  |_|_____|							\n";
}

void Renderer::printTextSpace() {
	std::cout << "			  / ____|								\n";
	std::cout << "			 | (___  _ __   __ _  ___ ___			\n";
	std::cout << "			  \\___ \\| '_ \\ / _` |/ __/ _ \\		\n";
	std::cout << "			  ____) | |_) | (_| | (_|  __/			\n";
	std::cout << "			 |_____/| .__/ \\__,_|\\___\\___|		\n";
	std::cout << "			        | |								\n";
	std::cout << "			        |_|								\n";
}

void Renderer::printTextShooter() {
	std::cout << "			   _____| |                _					\n";
	std::cout << "			  / ____| |               | |					\n";
	std::cout << "			 | (___ | |__   ___   ___ | |_ ___ _ __			\n";
	std::cout << "			  \\___ \\| '_ \\ / _ \\ / _ \\| __/ _ \\ '__|	\n";
	std::cout << "			  ____) | | | | (_) | (_) | ||  __/ |			\n";
	std::cout << "			 |_____/|_| |_|\\___/ \\___/ \\__\\___|_|		\n";
}

//			   __
//			   \ \_____
//			###[==_____>
//			   /_/ 
//         
//           
//       !
//       !
//       ^
//      / \
//     /___\
//    |=   =|
//    |     |
//    |     |
//    |     |
//    |     |
//    |     |
//    |     |
//    |     |
//    |     |
//    |     |
//   /|##!##|\
//  / |##!##| \
// /  |##!##|  \
//|  /       \  |
//| /         \ |
//|/           \|
//	   /\
//    |==|
//    |  |
//    |  |
//   /____\
//   |    | aa
//   |    |
//   |    |
//  /| |  |\
// / | |  | \
///__|_|__|__\
//   /_\/_\
//   ######
//  ########
//   ######
//    ####
//    ####
//     ##
//     ##   


void Renderer::printTextFmiWithRocket() {
	std::cout << "     /\\          ______ __  __ _____		   __				\n";
	std::cout << "    |==|         |  ____|  \\/  |_   _|		   \\ \\_____			\n";
	std::cout << "    |  |         | |__  | \\  / | | |		###[==_____>		\n";
	std::cout << "    |  |         |  __| | |\\/| | | |		   /_/ 				\n";
	std::cout << "   /____\\        | |    | |  | |_| |_							\n";
	std::cout << "   |    |        |_|____|_|  |_|_____|							\n";
}

void Renderer::printTextSpaceWithRocket() {
	std::cout << "   |    |         / ____|								\n";
	std::cout << "   |    |        | (___  _ __   __ _  ___ ___			\n";
	std::cout << "  /| |  |\\        \\___ \\| '_ \\ / _` |/ __/ _ \\		\n";
	std::cout << " / | |  | \\       ____) | |_) | (_| | (_|  __/			\n";
	std::cout << "/__|_|__|__\\     |_____/| .__/ \\__,_|\\___\\___|		\n";
	std::cout << "   /_\\/_\\               | |								\n";
	std::cout << "   ######               |_|								\n";
}

void Renderer::printTextShooterWithRocket() {
	std::cout << "  ########         _____| |                _					\n";
	std::cout << "   ######         / ____| |               | |					\n";
	std::cout << "    ####         | (___ | |__   ___   ___ | |_ ___ _ __			\n";
	std::cout << "    ####          \\___ \\| '_ \\ / _ \\ / _ \\| __/ _ \\ '__|	\n";
	std::cout << "     ##           ____) | | | | (_) | (_) | ||  __/ |			\n";
	std::cout << "     ##          |_____/|_| |_|\\___/ \\___/ \\__\\___|_|		\n";
}

void Renderer::printMainMenu() {
	std::cout << "\n\n\n";
	std::cout << "                        N --> New game\n";
	std::cout << "                        L --> Load saved game\n";
	std::cout << "                        H --> Help\n";
	std::cout << "                        E --> Exit\n";
	std::cout << std::endl;
}

void Renderer::printEmptyRows(int count) {
	for (int i = 0; i < count; i++) {
		std::cout << std::endl;
	}
}

void Renderer::printAnimation() {
	printTextFmi();
	Sleep(1000);

	Renderer::clearScreen();
	printEmptyRows(6);
	printTextSpace();
	Sleep(1000);

	Renderer::clearScreen();
	printEmptyRows(13);
	printTextShooter();
	Sleep(1000);
}

void Renderer::printStaticStartScreen() {
	Renderer::clearScreen();
	printTextFmiWithRocket();
	printTextSpaceWithRocket();
	printTextShooterWithRocket();
	printMainMenu();
}

void Renderer::printDifficultyOptions() {
	std::cout << "\n\n\n";
	std::cout << "                        Select Difficulty \n";
	std::cout << "                        E --> Easy\n";
	std::cout << "                        M --> Medium\n";
	std::cout << "                        I --> Intermediate\n";
	std::cout << std::endl;
}


void Renderer::renderStartScreen() {
	printAnimation();
	printStaticStartScreen();

}

void Renderer::renderDifficultySelectionScreen() {
	Renderer::clearScreen();
	printTextFmiWithRocket();
	printTextSpaceWithRocket();
	printTextShooterWithRocket();
	printDifficultyOptions();
}

void Renderer::renderInitialGameScreen(SpaceShooter* spaceShooter) {
	clearScreen();
	std::cout << "Score: " << spaceShooter->getPlayer()->getScore() << "   Lives: " << spaceShooter->getPlayer()->getRemainingLives();
	if (spaceShooter->bossFightIsInAction) {
		std::cout << "   Boss lives: " << spaceShooter->boss_container.at(0).getRemainingLives();
	}

	std::cout << std::endl;

	for (int i = 0; i < SCREEN_WIDTH; i++) {
		std::cout << "-";
	}

	std::cout << " " << std::endl;

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			std::cout << spaceShooter->updatedScreen[i][j];
			spaceShooter->renderedScreen[i][j] = spaceShooter->updatedScreen[i][j];
		}
		std::cout << "|" << std::endl;
	}

	for (int i = 0; i < SCREEN_WIDTH; i++) {
		std::cout << "-";
	}
	std::cout << " \n";

}

void Renderer::modifyRenderedScreen(SpaceShooter* spaceShooter) {
	GoToXY(0, 0);
	std::cout << "Score: " << spaceShooter->getPlayer()->getScore() << "   Lives: " << spaceShooter->getPlayer()->getRemainingLives();
	if (spaceShooter->bossFightIsInAction) {
		std::cout << "   Boss lives: " << spaceShooter->boss_container.at(0).getRemainingLives() << "   ";
	}
	else {
		std::cout << "                      ";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			if (spaceShooter->renderedScreen[i][j] != spaceShooter->updatedScreen[i][j]) {
				GoToXY(j, i + 2);
				std::cout << spaceShooter->updatedScreen[i][j];
				spaceShooter->renderedScreen[i][j] = spaceShooter->updatedScreen[i][j];
			}
		}
	}
}


//			 ____              _                 
//			/ ___|  __ ___   _(_)_ __   __ _     
//			\___ \ / _` \ \ / / | '_ \ / _` |    
//			 ___) | (_| |\ V /| | | | | (_| |    
//			|____/ \__,_| \_/ |_|_| |_|\__, |    
//			   ____                    |___/     
//			  / ___| __ _ _ __ ___   ___         
//			 | |  _ / _` | '_ ` _ \ / _ \        
//			 | |_| | (_| | | | | | |  __/  _   _ 
//			  \____|\__,_|_| |_| |_|\___| (_) (_)


void Renderer::printSavingGame() {
	//Renderer::clearScreen();
	//std::cout << std::endl << std::endl << std::endl;
	//std::cout << "           ____              _                 " << std::endl;
	//std::cout << "          / ___|  __ ___   _(_)_ __   __ _      " << std::endl;
	//std::cout << "          \\___ \\ / _` \\ \\ / / | '_ \\ / _` |     " << std::endl;
	//std::cout << "           ___) | (_| |\\ V /| | | | | (_| |     " << std::endl;
	//std::cout << "          |____/ \\__,_| \\_/ |_|_| |_|\\__, |     " << std::endl;
	//std::cout << "             ____                    |___/      " << std::endl;
	//std::cout << "            / ___| __ _ _ __ ___   ___          " << std::endl;
	//std::cout << "           | |  _ / _` | '_ ` _ \\ / _ \\         " << std::endl;
	//std::cout << "           | |_| | (_| | | | | | |  __/  _   _  " << std::endl;
	//std::cout << "            \\____|\\__,_|_| |_| |_|\\___| (_) (_) " << std::endl;
	//Sleep(1000);
	GoToXY(0, 0);
	std::cout << "Saving game..                                ";
	Sleep(1000);
}


//			 ______ _______ _______ _______
//			|  ____ |_____| |  |  | |______
//			|_____| |     | |  |  | |______
//			                               
//			                                             
//			                               
//			 _____  _    _ _______  ______ 
//			|     |  \  /  |______ |_____/ 
//			|_____|   \/   |______ |    \_              


void Renderer::printGameOverScreen(SpaceShooter* spaceShooter) {
	Renderer::clearScreen();
	std::cout << "           ______ _______ _______ _______  " << std::endl;
	std::cout << "          |  ____ |_____| |  |  | |______  " << std::endl;
	std::cout << "          |_____| |     | |  |  | |______  " << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "           _____  _    _ _______  ______   " << std::endl;
	std::cout << "          |     |  \\  /  |______ |_____/  " << std::endl;
	std::cout << "          |_____|   \\/   |______ |    \\_ " << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Difficulty: ";

	switch (spaceShooter->getDifficulty()) {
	case DIFFICULTY_EASY:			std::cout << "Easy" << std::endl;			break;
	case DIFFICULTY_MEDIUM:			std::cout << "Medium" << std::endl;			break;
	case DIFFICULTY_INTERMEDIATE:	std::cout << "Intermediate" << std::endl;	break;
	}

	std::cout << "Score:      " << spaceShooter->getPlayer()->getScore() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Sleep(2000);
	system("pause");
}

void Renderer::clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Renderer::GoToXY(int column, int line) {
	// Create a COORD structure and fill in its members.
	// This specifies the new position of the cursor that we will set.
	COORD coord;
	coord.X = column;
	coord.Y = line;

	// Obtain a handle to the console screen buffer.
	// (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
	// in conjunction with the GetStdHandle() to retrieve the handle.)
	// Note that because it is a standard handle, we don't need to close it.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Finally, call the SetConsoleCursorPosition function.
	if (!SetConsoleCursorPosition(hConsole, coord))
	{
		// Uh-oh! The function call failed, so you need to handle the error.
		// You can call GetLastError() to get a more specific error code.
		// ...
	}
}