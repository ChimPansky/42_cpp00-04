#include "DiamondTrap.hpp"
#include <iostream>
int	main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		DiamondTrap*	a = new DiamondTrap("Bob");
		std::cout << std::endl;

		DiamondTrap*	b = new DiamondTrap(*a);
		std::cout << std::endl;

		DiamondTrap*	c = new DiamondTrap();
		std::cout << std::endl;

		*c = *b;
		std::cout << std::endl;

		a->whoAmI();
		a->printStatus();
		b->whoAmI();
		b->printStatus();
		c->whoAmI();
		c->printStatus();

		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
	}
	{
		std::cout << std::endl;
		std::cout << "---SECTION 2---" << std::endl;

		DiamondTrap* diamond = new DiamondTrap("Shiny");
		diamond->attack("some other diamond");
		diamond->beRepaired(20);
		diamond->takeDamage(5);
		diamond->highFivesGuys();
		diamond->attack("Billy");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->attack("Joey");
		diamond->takeDamage(20);
		diamond->takeDamage(6);
		diamond->beRepaired(5);
		diamond->beRepaired(6);
		diamond->takeDamage(5);
		diamond->takeDamage(5);
		diamond->takeDamage(5);
		diamond->beRepaired(5);
		diamond->attack("Bob");
		delete diamond;
		return (0);
	}
}
