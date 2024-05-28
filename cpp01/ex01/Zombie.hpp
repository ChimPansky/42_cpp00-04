#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>


class Zombie {
	private:
	std::string	_name;

	public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();

	void	announce(void);
	void	setName(const std::string& name);
};

// zombieHorde.cpp:
Zombie* zombieHorde(int N, const std::string& name);

#endif
