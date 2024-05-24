#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
	std::string	_name;

	public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

#endif
