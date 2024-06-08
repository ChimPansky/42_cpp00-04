
#include "List.hpp"
#include <iostream>

int	main() {
	List	L1;
	char	a = 42;
	char*	ptr = &a;

	L1.lAppend(ptr);
	L1.lAppend(ptr + 1);
	L1.lAppend(ptr + 1);
	L1.lAppend(ptr);
	L1.lAppend(ptr + 1);
	L1.lAppend(ptr);

	std::cout << "L1.lSize(): " << L1.lSize() << std::endl;
	L1.lPrint();
	std::cout << std::endl;
	List L2(L1);


	L1.lRemove(ptr + 1);
	std::cout << "L1.lSize(): " << L1.lSize() << std::endl;
	L1.lPrint();
	std::cout << std::endl;

	std::cout << "L2.lSize(): " << L1.lSize() << std::endl;
	L2.lPrint();
	std::cout << std::endl;

}
