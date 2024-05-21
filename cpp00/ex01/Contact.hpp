#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
	std::string _lastName;

	public:
	Contact();
	~Contact();
	
	std::string	getLastName();
};

#endif
