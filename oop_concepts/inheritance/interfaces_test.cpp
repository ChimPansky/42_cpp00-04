#include <iostream>

class A {
  public:
	virtual void hello() = 0;
	virtual ~A() {std::cout << "A::Deconstructor" << std::endl;};
};

class B: public A {
  public:
	void 	hello() {	std::cout << "B::hello!" << std::endl;	}
	void	hello2() {	std::cout << "B::hello2!" << std::endl;	}
	~B() {std::cout << "B::Deconstructor" << std::endl;}
};

int main() {
	A* test = new B();
	test->hello();
	dynamic_cast<B*>(test)->hello2();
	delete test;
}
