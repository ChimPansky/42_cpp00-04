#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << ": So long! And thanks for all the Brainzzz..." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
