#include <iostream>
class A {
	protected:
	int val;
};

class B : virtual A {
	public:
	B() {
		val = 42;
	}
	void print() {
		std::cout << "B::val: " << B::val << std::endl;
		std::cout << "A:val: " << A::val << std::endl;
	}
};

class C: virtual A {
	int val;
};

class D: B, C {
	int val;
	public:
	void print() {
		std::cout << "val: " << val << std::endl;
		// std::cout << "A:val: " << A::val << std::endl;
	}
};

int main() {
	B test;
	test.print();
}
