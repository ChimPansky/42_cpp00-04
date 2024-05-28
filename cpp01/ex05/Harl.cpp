#include "Harl.hpp"
#include <iostream>
#include <string>

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\nGot bugs? No problem - Harl has got you! Here is some debug text in "
		"order to help you find them. May it help you fix your shitty code!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]\nEverything is fine - don't worry! This is just some message that "
		"prints out some information for your consideration." << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\n This is a warning. Something is not quite right. You can chose to "
		"ignore me, but be warned that you might regret that decision later!" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\nOkay this is bad. An error happened. Maybe you should not have "
		"ignored all those previous warnings. \nNot saying that I told you so, "
		"but well I told you so!" << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*harlFunctions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return (this->*harlFunctions[i])();
	}
	std::cout << "[404 Not found] \nHarl was not able to complain. Level not found: " << level << std::endl;
}
