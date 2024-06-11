#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

const int	zooSize = 6;

int	main() {
	Animal*	zoo[zooSize];

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

	std::cout << "\n\n---Cat Tests for deep copy:\n" << std::endl;
	{
		Cat	kitty1;
		Cat kitty2(kitty1);

		std::cout << "\nkitty brain: " << kitty1.getBrain() << std::endl;
		std::cout << "kitty2 brain: " << kitty2.getBrain() << "\n" << std::endl;
		kitty1.getBrain()->setIdea(0, "Push porcelain figures from shelves.");
		kitty2.getBrain()->setIdea(0, "Catch tail.");
		std::cout << "kitty idea 0: " << kitty1.getBrain()->getIdea(0) << std::endl;
		std::cout << "kitty2 idea 0: " << kitty2.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\n---Dog Tests for deep copy:\n" << std::endl;
	{
		Dog	doggo1;
		Dog doggo2(doggo1);

		std::cout << "\ndoggo brain: " << doggo1.getBrain() << std::endl;
		std::cout << "doggo2 brain: " << doggo2.getBrain() << "\n" << std::endl;
		doggo1.getBrain()->setIdea(0, "Do some sniffin.");
		doggo2.getBrain()->setIdea(0, "Look for something to eat. Literally anything.");
		std::cout << "doggo idea 0: " << doggo1.getBrain()->getIdea(0) << std::endl;
		std::cout << "doggo idea 0: " << doggo2.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}
}
