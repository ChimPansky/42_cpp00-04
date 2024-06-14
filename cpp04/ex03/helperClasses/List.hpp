#pragma once

#include <cstddef>

#define LIST_VERBOSE 0
#if LIST_VERBOSE
# define LIST_VERBOSE_OUT(msg) std::cout << msg << std::endl;
#else
# define LIST_VERBOSE_OUT(msg)
#endif

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
	tNode*	find(void* value) const;
	void	print() const;
};
