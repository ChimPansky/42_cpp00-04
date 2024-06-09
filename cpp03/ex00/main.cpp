#include "ClapTrap.hpp"

int	main() {
	ClapTrap	a;
	ClapTrap	b("Clappy");
	ClapTrap	c(b);
	c = b;

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

	return (0);
}
