#include "FragTrap.hpp"
#include <iostream>

int	main() {
	{
		std::cout << "---SECTION 1---" << std::endl;
		ClapTrap*	a = new ClapTrap("Clappy");
		ClapTrap*	b = new FragTrap("Fraggy1");
		FragTrap*	c = new FragTrap("Fraggy2");
		FragTrap*	d = new FragTrap(*c);
		FragTrap*	e = new FragTrap;
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
