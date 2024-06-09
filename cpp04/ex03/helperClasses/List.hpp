#pragma once

#include <cstddef>

#ifndef SUCCESS
# define SUCCESS 0
#endif
#ifndef FAILURE
# define FAILURE !SUCCESS
#endif

typedef struct sNode {
	void*			val;
	struct sNode*	next;
}				tNode;

class List {
  private:
	tNode*	_head;

  public:
	List();
	List(const List& other);
	List& operator=(const List& other);
	~List();

	tNode*	getHead() const;
	void*	getVal(tNode* node) const;
	void	deleteAll();
	size_t	size() const;
	bool	isEmpty() const;
	tNode*	last() const;
	int		append(void* value);
	int		remove(void* value);
	void	print() const;
};
