#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

std::string	truncate(std::string str, size_t len);
void		printField(std::string field, int width, char separator);
std::string	intToString(int nbr);
std::string	strToUpper(std::string str);
std::string	readLine(std::string prompt);

#endif
