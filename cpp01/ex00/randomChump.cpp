#include "Zombie.hpp"

void	randomChump(const std::string& name) {
	Zombie	stackZombie(name);

	stackZombie.announce();
}
