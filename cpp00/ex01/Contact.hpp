#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook_utils.hpp"
# include <string>

class Phonebook;

class Contact {
	private:
	std::string	_fields[FIELD_COUNT];

	public:
	Contact();
	Contact(std::string fname, std::string lname,
		std::string nick, std::string phoneNr, std::string secret);
	~Contact();

	std::string*	getFields();

	void	printOverview();
	void	setIndex(int index);
};

#endif
