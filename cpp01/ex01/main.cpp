#include "Zombie.hpp"
#include <iostream>

int	main() {
	int	hordeSize = 10;

	Zombie* heapZombies = zombieHorde(hordeSize, "Average Bob");

	std::cout << std::endl;

	for (int i = 0; i < hordeSize; i++) {
		heapZombies[i].announce();
	}

	std::cout << std::endl;

	delete[] heapZombies;
	return (0);
}
