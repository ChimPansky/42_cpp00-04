#include <iostream>

class	Base {
  protected:
	int	_value;

  public:
	Base() { _value = 42;}
	void	sayHello() {
		std::cout << "Base class says Hello!" << std::endl;
	}
};

class	Derived: public Base {
  private:

  public:
	Derived() {Base::_value = 24;	Derived::_value=84;}
	void	sayHello() {
		std::cout << "Derived class says Hello!" << std::endl;
		std::cout << "Base::val: " << Base::_value << std::endl;
		std::cout << "Derived::val: " << Derived::_value << std::endl;
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
