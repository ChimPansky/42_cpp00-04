#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int	main() {
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();

		club.setType("favorite baseball bat");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.attack();

		jim.setWeapon(club);
		jim.attack();

		club.setType("favorite baseball bat");
		jim.attack();
	}
	return (0);
}
