#include <iostream>
#include <string>
#include <cctype>

std::string	strToUpper(std::string message) {
	for (int i = 0; i < (int)message.size(); i++)
		message[i] = std::toupper(message[i]);
	return (message);
}

int 	main(int argc, char *argv[]) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < argc; i++)
			std::cout << strToUpper(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}
