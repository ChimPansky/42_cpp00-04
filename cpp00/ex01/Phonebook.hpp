#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "phonebook_utils.hpp"

# define MAX_CONTACTS 8

class Phonebook {
	private:

	Contact 	_contacts[MAX_CONTACTS];
	std::string _fieldNames[FIELD_COUNT];
	int			_entries;
	void		_addContact(Contact newContact);
	void		_printContacts();
	void		_printContactDetail(int index);
	bool		_fieldValueIsValid(const std::string& str);
	bool		_strIsNum(const std::string& str);
	bool		_strToInt(const std::string& str, int& target);

	public:

	Phonebook();
	~Phonebook();
	void		add();
	void		search();
};

#endif
