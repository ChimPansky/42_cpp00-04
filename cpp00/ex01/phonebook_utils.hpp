#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

# define SUCCESS 0
# define FAILURE 1
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

void		printField(std::string field, int width, char separator);
std::string	strTrim(const std::string& str);
std::string	readLine(const std::string& prompt);

#endif
