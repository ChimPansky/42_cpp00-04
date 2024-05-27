#include "fileUtils.hpp"
# include <iostream>
# include <string>

int	openInFile(std::ifstream& fStream, const std::string& fPath) {
	fStream.open(fPath.c_str());
	if (fStream.fail()) {
		std::cerr << "Error opening file: " << fPath << std::endl;
		return (ERROR);
	}
	return (SUCCESS);
}

// Todo: merge these 2 functions??
int	openOutFile(std::ofstream& fStream, const std::string& fPath) {
	fStream.open(fPath.c_str());
	if (fStream.fail()) {
		std::cerr << "Error opening file: " << fPath << std::endl;
		return (ERROR);
	}
	return (SUCCESS);
}

std::string	readFileContent(std::ifstream& inStream) {
	std::string	line;
	std::string	content = "";

	content = "";
	while (std::getline(inStream, line))
		content += line;
	return (content);
}

std::string	stringReplace(const std::string& sourceStr, const char* searchCstr, const char* replaceCstr) {
	std::string				search(searchCstr);
	std::string				replace(replaceCstr);
	std::string				newStr = "";
	std::string::size_type	sourcePos = 0;
	std::string::size_type	searchHit = 0;

	while ((searchHit = sourceStr.find(search, sourcePos)) != std::string::npos) {
		std::cout << "searchhit: " << searchHit << std::endl;
		std::cout << "substr: " << sourceStr.substr(sourcePos, searchHit - sourcePos) << std::endl;
		newStr.append(sourceStr, sourcePos, searchHit - sourcePos);
		newStr.append(replace);
		sourcePos += search.length();
	}
	return (newStr);
}
