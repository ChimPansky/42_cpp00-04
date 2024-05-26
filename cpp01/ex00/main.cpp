#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie	z1("Ed");
	z1.announce();

	std::cout << std::endl;

	Zombie* heapZombie = newZombie("Fred");
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl;

	randomChump("Bob");

	return (0);
}
