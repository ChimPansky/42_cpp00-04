#include "Phonebook.hpp"
#include "phonebook_utils.hpp"
#include <iostream>
#include <string>

int	main() {
	Phonebook	awesomePB;
	std::string	userInput;

	while (true)
	{
		if (std::cin.eof()) {
			std::cout << "OK BYE!" << std::endl;
			break ;
		}
		userInput = strTrim(readLine("Please enter a command (ADD/SEARCH/EXIT)"));
		if (userInput == "ADD" || userInput == "add") {
			awesomePB.add();
		}
		else if (userInput == "SEARCH" || userInput == "search")
			awesomePB.search();
		else if (userInput == "EXIT" || userInput == "exit" || std::cin.eof()) {
			std::cout << "OK BYE!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command: " << userInput << std::endl;
	}
	return (SUCCESS);
}
