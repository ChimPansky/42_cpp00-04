#include "Phonebook.hpp"
#include "phonebook_utils.hpp"
#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 1

int	main() {
	Phonebook	awesomePB;
	std::string	userInput;
	bool		exit;

	awesomePB.printContacts();
	// awesomePB.addContact(Contact("Bruce0", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce1", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce2", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce3", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce4", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce5", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce6", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce7", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce8", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce9", "Banner", "Batsy", "+43 0544648634", "hates bats"));
	// awesomePB.addContact(Contact("Bruce10", "Banner", "Batsy", "+43 0544648634", "hates bats"));

	// awesomePB.addContact(Contact("1", "Wayne"));
	// awesomePB.addContact(Contact("1", "Reece"));
	// awesomePB.printContacts();
	// awesomePB.printContactDetail(0);
	// awesomePB.printContactDetail(1);
	// awesomePB.printContactDetail(2);
	// awesomePB.printContactDetail(9);

	exit = false;
	while (!exit)
	{
		userInput = strToUpper(readLine("Please enter a command (ADD/SEARCH/EXIT)."));
		if (userInput == "ADD") {
			awesomePB.add();
			awesomePB.printContacts();
			awesomePB.printContactDetail(0);
		}
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
