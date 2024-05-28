#include <iostream>
#include "fileUtils.hpp"


int main (int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments! Expecting 3: "
			<< "filename, string-to-replace and replace-with-string." << std::endl;
			return (ERROR);
	}
	if (fileStrReplace(argv[1], argv[2], argv[3]) != SUCCESS)
		return (ERROR);
	std::cout << "Finished without errors!" << std::endl;
	return (SUCCESS);

}
