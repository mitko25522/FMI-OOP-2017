#pragma once


enum Choice {
	NEW_GAME,
	LOAD_GAME,
	HELP,
	EXIT
};

class InputHandler {
public:
	static Choice handleGameMenu();
};