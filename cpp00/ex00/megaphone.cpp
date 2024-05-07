#include <iostream>

void	ft_putstr(char *str)
{
	for (int i = 0; i < )

}

int main(int argc, char *argv[])
{
	if (argc < 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i];
		}
	}
	std::cout << std::endl;
	return (0);
}
