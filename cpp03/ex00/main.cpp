#include "ClapTrap.hpp"
#include <iostream>
int	main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		ClapTrap	a;
		ClapTrap	b("Clappy");
		ClapTrap	c(a);

		a.printStatus();
		b.printStatus();
		c.printStatus();
		c = b;
		c.printStatus();
	}
	{
		std::cout << std::endl;
		std::cout << "---SECTION 2---" << std::endl;
		ClapTrap	a;
		ClapTrap	b("Clappy");
		a.attack("Clapdude");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");
		b.attack("Joey");

		b.takeDamage(5);
		a.takeDamage(6);

		b.beRepaired(5);
		a.beRepaired(6);
		b.takeDamage(5);
		b.takeDamage(5);
		b.takeDamage(5);
		b.beRepaired(5);
		b.attack("Bob");
		// b.takeDamage(5);
	}

	return (0);
}
