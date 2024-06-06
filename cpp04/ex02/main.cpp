#include "Dog.hpp"
#include "Cat.hpp"
#include "IAnimal.hpp"
#include <iostream>

const int	zooSize = 6;

int	main() {
	// IAnimal*	invalid = new IAnimal;	Not possible!

	Cat*		kitty = new Cat;
	kitty->makeSound();
	delete kitty;

	 IAnimal*	zoo[zooSize];

	for (int i = 0; i < zooSize; i++) {
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	for (int i = 0; i < zooSize; i++) {
		std::cout << "zoo[" << i << "]: type: " << zoo[i]->getType() << "; ";
		zoo[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < zooSize; i++) {
		delete zoo[i];
	}

	std::cout << "\n\n---Tests for deep copy:\n" << std::endl;
	{
		Cat	kitty;
		Cat kitty2(kitty);

		std::cout << "\nkitty brain: " << kitty.getBrain() << std::endl;
		std::cout << "kitty2 brain: " << kitty2.getBrain() << "\n" << std::endl;
	}
	std::cout << std::endl;
	{
		Dog	doggo;
		Dog doggo2(doggo);

		std::cout << "\ndoggo brain: " << doggo.getBrain() << std::endl;
		std::cout << "doggo2 brain: " << doggo2.getBrain() << "\n" << std::endl;
	}
}
