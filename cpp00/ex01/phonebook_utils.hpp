#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

# define SUCCESS 0
# define FAILURE 1
# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10
# define COLUMN_SEPARATOR '|'

enum	eFieldIndizes {
	FIELD_INDEX,
	FIELD_FNAME,
	FIELD_LNAME,
	FIELD_NICK,
	FIELD_PHONENR,
	FIELD_SECRET,
	FIELD_COUNT
};

std::string	truncate(std::string str, size_t len);
void		printField(std::string field, int width, char separator);
std::string	intToString(int nbr);
std::string	strToUpper(std::string str);
std::string	readLine(std::string prompt);
bool		strToInt(const std::string& str, int& target);

#endif
