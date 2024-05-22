#include "Contact.hpp"
#include "Phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 1

int	main() {
	Phonebook	awesomePB;
	std::string	userInput;
	bool		exit;

	exit = false;
	while (!exit)
	{
		userInput = strToUpper(readLine("Please enter a command (ADD/SEARCH/EXIT)."));
		if (userInput == "ADD")
			awesomePB.add();
		else if (userInput == "SEARCH")
			awesomePB.search();
		else if (userInput == "EXIT") {
			exit = true;
			std::cout << "exiting..." << std::endl;
		}
		else
			std::cout << "Invalid command..." << std::endl;
	}





	// testPB.addContact(Contact("Basdasdfasdfill", "Weasley", "Billyboy12345"));
	// testPB.addContact(Contact("Ted", "Bundy", "BunnyBundy99999"));
	// testPB.addContact(Contact("BOB", "Bro", "BB"));
	// testPB.addContact(Contact("Luke", "Skywalker", "One-Hand-Luke"));
	// testPB.addContact(Contact("Lea", "Skywalker", "Jabba-Strangler"));
	// testPB.addContact(Contact("Last", "Skywalker", "LLOOOOONNNNGGGGG"));
	// testPB.printContacts();
	// testPB.printContactDetail(0);
	// testPB.printContactDetail(1);
	// testPB.printContactDetail(2);
	// testPB.printContactDetail(3);
	// testPB.printContactDetail(4);
	// testPB.printContactDetail(5);
	return (SUCCESS);
}
