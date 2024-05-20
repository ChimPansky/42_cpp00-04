#include <iostream>
#include <string>
#include <cctype>

void	strToUpper(std::string &message) {
	for (int i = 0; i < (int)message.size(); i++)
		message[i] = std::toupper(message[i]);
}

int 	main(int argc, char *argv[]) {
	std::string	message;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < argc; i++) {
			message = argv[i];
			strToUpper(message);
			std::cout << message;
		}
	}
	std::cout << std::endl;
	return (0);
}
