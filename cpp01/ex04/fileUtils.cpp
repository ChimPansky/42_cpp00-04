#include "fileUtils.hpp"
#include <iostream>
#include <string>
#include <sstream>


int	openInFile(std::ifstream& fStream, const std::string& fPath) {
	fStream.open(fPath.c_str());
	if (!fStream.is_open()) {
		std::cerr << "Error opening file: " << fPath << std::endl;
		return (ERROR);
	}
	return (SUCCESS);
}

int	openOutFile(std::ofstream& fStream, const std::string& fPath) {
	fStream.open(fPath.c_str());
	if (!fStream.is_open()) {
		std::cerr << "Error opening file: " << fPath << std::endl;
		return (ERROR);
	}
	return (SUCCESS);
}

std::string	readFileContent(std::ifstream& inStream) {
	std::string			line;
	std::string			content;
	std::stringstream	buffer;

	buffer << inStream.rdbuf();
	content = buffer.str();
	return (content);
}

std::string	stringReplace(const std::string& sourceStr, const char* searchCstr, const char* replaceCstr) {
	std::string				search(searchCstr);
	std::string				replace(replaceCstr);
	std::string				newStr;
	std::string::size_type	sourcePos = 0;
	std::string::size_type	searchHit = 0;

	if (search.length() < 1)
		return (sourceStr);
	while ((searchHit = sourceStr.find(search, sourcePos)) != std::string::npos) {
		newStr.append(sourceStr, sourcePos, searchHit - sourcePos);
		newStr.append(replace);
		sourcePos = searchHit + search.length();
	}
	if (sourcePos < sourceStr.length())
		newStr.append(sourceStr, sourcePos, sourceStr.length() - sourcePos);
	return (newStr);
}
