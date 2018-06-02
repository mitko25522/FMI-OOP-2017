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

	system("cls");
	printEmptyRows(6);
	printTextSpace();
	Sleep(1000);

	system("cls");
	printEmptyRows(13);
	printTextShooter();
	Sleep(1000);
}

void Renderer::printStaticStartScreen() {
	system("cls");
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
	system("cls");
	printTextFmiWithRocket();
	printTextSpaceWithRocket();
	printTextShooterWithRocket();
	printDifficultyOptions();
}

Renderer::Renderer() {

}

Renderer::~Renderer() {


}