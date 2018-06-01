#include "Renderer.h"
#include <windows.h>

void Renderer::printTextFmi() {
	std::cout << "			  ______ __  __ _____\n";
	std::cout << "			 |  ____|  \\/  |_   _|\n";
	std::cout << "			 | |__  | \\  / | | |\n";
	std::cout << "			 |  __| | |\\/| | | |\n";
	std::cout << "			 | |    | |  | |_| |_ \n";
	std::cout << "			 |_|____|_|  |_|_____|\n";
}

void Renderer::printTextSpace() {
	std::cout << "			  / ____|\n";
	std::cout << "			 | (___  _ __   __ _  ___ ___\n";
	std::cout << "			  \\___ \\| '_ \\ / _` |/ __/ _ \\\n";
	std::cout << "			  ____) | |_) | (_| | (_|  __/\n";
	std::cout << "			 |_____/| .__/ \\__,_|\\___\\___|\n ";
	std::cout << "			        | |\n";
	std::cout << "			        |_|                 \n";
}

void Renderer::printTextShooter() {
	std::cout << "			   _____| |                _ \n";
	std::cout << "			  / ____| |               | |\n";
	std::cout << "			 | (___ | |__   ___   ___ | |_ ___ _ __\n";
	std::cout << "			  \\___ \\| '_ \\ / _ \\ / _ \\| __/ _ \\ '__|\n";
	std::cout << "			  ____) | | | | (_) | (_) | ||  __/ |   \n";
	std::cout << "			 |_____/|_| |_|\\___/ \\___/ \\__\\___|_|\n";
}

void Renderer::printGameOptions() {
	std::cout << "\n\n\n";
	std::cout << "                           N --> New game\n";
	std::cout << "                           L --> Load saved game\n";
	std::cout << "                           H --> Help\n";
	std::cout << "                           E --> Exit\n";
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
	printTextFmi();
	printTextSpace();
	printTextShooter();
	printGameOptions();
}

void Renderer::renderStartScreen() {
	printAnimation();
	printStaticStartScreen();
	
}

Renderer::Renderer() {

}

Renderer::~Renderer() {


}