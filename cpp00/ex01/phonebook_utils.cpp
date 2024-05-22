#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

std::string	truncate(std::string str, size_t len) {
	std::string truncated_string;

	if (str.length() <= len)
		return (str);
	truncated_string = str.substr(0,len);
	truncated_string[len - 1] = '.';
	return (truncated_string);
}

void		printField(std::string field, int width, char separator) {
	std::cout << std::setw(width) << truncate(field, width);
	std::cout << separator;
}

std::string	intToString(int nbr) {
	std::ostringstream	temp_str;

	temp_str << nbr;
	return (temp_str.str());
}

std::string	strToUpper(std::string str) {
	for (int i = 0; i < (int)str.size(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

std::string	readLine(std::string prompt) {
	std::string input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	return (input);
}
