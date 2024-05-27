#include "fileUtils.hpp"
# include <iostream>

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

int	readFileContent(std::ifstream& inStream, std::string& inContent) {
	(void)inStream;
	(void)inContent;
	return (SUCCESS);
}

int	stringReplace(std::string src, std::string dst, char* searchStr, char* replaceStr) {

}
