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

	void	listDeleteAll();
	size_t	lSize() const;
	bool	lIsEmpty() const;
	tNode*	lLast() const;
	int		lAppend(void* value);
	int		lRemove(void* value);
	void	lPrint() const;
};
