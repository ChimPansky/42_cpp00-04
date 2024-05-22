#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

	public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickName);
	~Contact();

	std::string	getFirstName();
	std::string	getLastName();

	void	printOverview();
	void	printDetail();
};

#endif
