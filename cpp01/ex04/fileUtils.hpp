#ifndef FILEUTILS_HPP
# define FILEUTILS_HPP

# include <string>
#include <fstream>

# ifndef SUCCESS
#  define SUCCESS 0
# endif
# ifndef ERROR
#  define ERROR 1
# endif

int	openInFile(std::ifstream& fStream, const std::string& fPath);
int	openOutFile(std::ofstream& fStream, const std::string& fPath);
std::string	readFileContent(std::ifstream& inStream);
std::string	stringReplace(const std::string& src, const char* searchStr, const char* replaceStr);

#endif
