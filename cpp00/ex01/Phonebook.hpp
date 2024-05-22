#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10
# define COLUMN_SEPARATOR '|'

class Phonebook {
	private:
	Contact _contacts[MAX_CONTACTS];
	int		_entries;

	public:
	Phonebook();
	~Phonebook();

	void	addContact(Contact newContact);
	void	printContacts();
	void	printContactDetail(int index);

	void	add();
	void	search();
};

#endif
