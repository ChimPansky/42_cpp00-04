#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
	private:
	Contact _contacts[8];

	public:
	Phonebook();
	~Phonebook();

	void	addContact(Contact newContact);
	void	showContacts();
	Contact	*findContactByIndex(int searchIndex);
};

#endif
