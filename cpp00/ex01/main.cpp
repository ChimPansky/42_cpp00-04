#include "Phonebook.hpp"
#include "phonebook_utils.hpp"
#include <iostream>
#include <string>

int	main() {
	Phonebook	awesomePB;
	std::string	userInput;
	bool		exit;

	//awesomePB.printContacts();


	exit = false;
	while (!exit)
	{
		userInput = strToUpper(readLine("Please enter a command (ADD/SEARCH/EXIT)"));
		if (userInput == "ADD") {
			awesomePB.add();
			awesomePB.printContacts();
			awesomePB.printContactDetail(0);
		}
		else if (userInput == "SEARCH")
			awesomePB.search();
		else if (userInput == "EXIT" || std::cin.eof()) {
			exit = true;
			std::cout << "exiting..." << std::endl;
		}
		else
			std::cout << "Invalid command..." << std::endl;
	}
	return (SUCCESS);
}
