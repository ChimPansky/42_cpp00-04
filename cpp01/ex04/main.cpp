#include <iostream>
#include <string>
#include "fileUtils.hpp"


int main (int argc, char **argv) {
	std::string		inFilePath;
	std::string		outFilePath;
	std::ifstream	inFileStream;
	std::ofstream	outFileStream;
	std::string		inFileContent;
	std::string		newContent;

	if (argc != 4) {
		std::cerr << "Wrong number of arguments! Expecting 3: "
			<< "filename, string-to-replace and replace-with-string." << std::endl;
			return (ERROR);
	}
	inFilePath = argv[1];
	outFilePath = inFilePath + ".replace";
	if (openInFile(inFileStream, inFilePath) != SUCCESS)
		return (ERROR);
	if (openOutFile(outFileStream, outFilePath) != SUCCESS)
		return (inFileStream.close(), ERROR);
	inFileContent = readFileContent(inFileStream);
	std::cout << inFileContent << std::endl;
	newContent = stringReplace(inFileContent, argv[2], argv[3]);

	// outFileStream << "Test" << std::endl;
	outFileStream << newContent << std::endl;
	if (outFileStream.fail()) {
		std::cerr << "Error writing to file: " << outFilePath << std::endl;
		return (inFileStream.close(), outFileStream.close(), ERROR);
	}

	inFileStream.close();
	outFileStream.close();
	std::cout << "Finished without errors!" << std::endl;

	return (SUCCESS);

}
