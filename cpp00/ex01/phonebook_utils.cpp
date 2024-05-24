#include "phonebook_utils.hpp"
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

static std::string	truncate(std::string str, size_t len) {
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

std::string	strTrim(const std::string& str) {
	size_t	start = 0;
	size_t	end = str.length();

	while (start < str.length() && std::isspace(str[start]))
		start++;
	while (end > start && std::isspace(str[end - 1]))
		end--;
	return (str.substr(start, end - start));
}

std::string	readLine(const std::string& prompt) {
	std::string input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::cout << "EOF" << std::endl;
	return (input);
}
