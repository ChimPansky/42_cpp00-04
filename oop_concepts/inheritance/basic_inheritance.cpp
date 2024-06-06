#include <iostream>

class	Base {
  private:
	int	_value;

  public:
	void	sayHello() {
		std::cout << "Base class says Hello!" << std::endl;
	}
};

class	Derived: public Base {
  private:

  public:
	void	sayHello() {
		std::cout << "Derived class says Hello!" << std::endl;
	}
};

int	main() {
	Derived d1;

	d1.sayHello();

	Base	b1;
	b1.sayHello();

	Base	*basePtr;

	basePtr = &d1;
	basePtr->sayHello();
	return 0;
}
