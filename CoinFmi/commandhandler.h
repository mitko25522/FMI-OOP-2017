#pragma once

enum Choice
{
	invalid,
	quit,
	help,
	addwallet,
	walletinfo,
	attractinvestors,
	makeorder
};

Choice determineChoice(char*);