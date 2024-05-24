#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook_utils.hpp"

class Phonebook;

class Contact {
	private:
	std::string		_fields[FIELD_COUNT];
	std::string		_intToString(int nbr);

	public:
	Contact();
	Contact(
		std::string fname,
		std::string lname,
		std::string nick,
		std::string phoneNr,
		std::string secret);
	~Contact();
	void			printOverview();
	void			setIndex(int index);
	std::string*	getFields();
};

#endif
