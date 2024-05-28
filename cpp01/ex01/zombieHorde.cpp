#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name) {
	if (N < 1)
		return (NULL);
	Zombie*	heapZombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		heapZombies[i].setName(name);
	}

	return (heapZombies);
}
