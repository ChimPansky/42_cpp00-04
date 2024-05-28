#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl	complainer;

	if (argc != 2)
		return ((std::cerr << "Please specify a Filter for Harl (DEBUG/INFO/WARNING/ERROR)" << std::endl), 1);
	complainer.complain(argv[1]);
	return (0);
}
