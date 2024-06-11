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

	// public methods:
	const std::string&	getIdea(int idx) const;
	void				setIdea(int idx, const std::string& idea);

  private:
	std::string					_ideas[brainIdeaCount];
	// statics:
	static const std::string	_className;
	static const std::string	_invalidIndexString;
};
