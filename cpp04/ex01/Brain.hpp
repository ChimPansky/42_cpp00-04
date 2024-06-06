#pragma once

#include <string>

//TODO: fill brain with random ideas and use getIdeas[index] to show contents...
static const int	brainIdeaCount = 100;

class Brain {
  public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	// Getters:
	std::string*	getIdeas();

  private:
	std::string					_ideas[brainIdeaCount];
	static const std::string	_className;
};
