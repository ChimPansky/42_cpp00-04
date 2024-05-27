#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>


class Zombie {
  private:
	std::string	_name;

  public:
	Zombie(const std::string& name);
	~Zombie();

	void	announce(void);
};

// newZombie.cpp:
Zombie* newZombie(const std::string& name);

// randomChump.cpp:
void	randomChump(const std::string& name);

#endif
