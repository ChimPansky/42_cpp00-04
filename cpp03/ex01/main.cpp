#include "ScavTrap.hpp"
#include <iostream>

int	main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		ClapTrap*	a = new ClapTrap("Clappy");
		ClapTrap*	b = new ScavTrap("Scavvy");
		ScavTrap*	c = new ScavTrap("Scabby");
		ScavTrap*	d = new ScavTrap(*c);
		ScavTrap*	e = new ScavTrap;
		*e = *d;
		std::cout << std::endl;

		a->printStatus();
		b->printStatus();
		c->printStatus();
		d->printStatus();
		e->printStatus();

		std::cout << std::endl;
		c->attack("random victim");

		a->printStatus();
		b->printStatus();
		c->printStatus();
		d->printStatus();
		e->printStatus();
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		delete d;
		delete e;
	}
	{
		std::cout << std::endl;
		std::cout << "---SECTION 2---" << std::endl;

		ScavTrap* scav = new ScavTrap("Scavvy");
		scav->printStatus();
		scav->attack("some other trap");
		scav->beRepaired(20);
		scav->takeDamage(5);
		scav->guardGate();

		scav->attack("Scavdude");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->attack("Joey");
		scav->takeDamage(20);
		scav->takeDamage(6);
		scav->beRepaired(5);
		scav->beRepaired(6);
		scav->takeDamage(5);
		scav->takeDamage(5);
		scav->takeDamage(5);
		scav->beRepaired(5);
		scav->attack("Bob");

		delete scav;
		return (0);
	}
}
