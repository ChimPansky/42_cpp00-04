#pragma once

#include <string>
class Climber {
private:
	std::string _name;
	std::string *_ascents;

public:
  Climber(const std::string &name);
  Climber(const Climber &other);
  Climber &operator=(const Climber &other);
  ~Climber();

  std::string getName();
  std::string *getAscents();
  void	setName(const std::string &name);
  void	addAscent(const std::string &name);
};
