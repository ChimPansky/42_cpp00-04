#include "DiamondTrap.hpp"
#include <iostream>
int	main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		DiamondTrap*	a = new DiamondTrap("Bob");
		DiamondTrap*	b = new DiamondTrap(*a);
		DiamondTrap*	c = new DiamondTrap();
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
	return 0;
	{
		std::cout << std::endl;
		std::cout << "---SECTION 2---" << std::endl;

		FragTrap* frag = new FragTrap("Fraggy");
		frag->attack("some other trap");
		frag->beRepaired(20);
		frag->takeDamage(5);
		frag->highFivesGuys();

		frag->attack("Fragdude");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->attack("Joey");
		frag->takeDamage(20);
		frag->takeDamage(6);
		frag->beRepaired(5);
		frag->beRepaired(6);
		frag->takeDamage(5);
		frag->takeDamage(5);
		frag->takeDamage(5);
		frag->beRepaired(5);
		frag->attack("Bob");

		delete frag;
		return (0);
	}
}
