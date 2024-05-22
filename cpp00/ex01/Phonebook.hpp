#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "phonebook_utils.hpp"

class Phonebook {
	private:
	Contact 	_contacts[MAX_CONTACTS];
	std::string _fieldNames[FIELD_COUNT];
	int			_entries;

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
