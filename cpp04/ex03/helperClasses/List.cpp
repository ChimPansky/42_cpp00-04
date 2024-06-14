#include "List.hpp"
#include <iostream>

// constructors, copy assignment operator overload and destructor:
List::List()
	: _head(0) {
	LIST_VERBOSE_OUT("List:: Constructor() called");
	}

List::List(const List& other)
	: _head(0) {
	LIST_VERBOSE_OUT("List:: Copy Constructor called");
		*this = other;
}

List&	List::operator=(const List& other) {
	LIST_VERBOSE_OUT("List:: Copy assignment operator overload called");
	if (this == &other)
		return *this;
	if (!this->isEmpty())
		deleteAll();
	if (!other.isEmpty()) {
		tNode* cur = other._head;
		while (cur) {
			append(cur->val);
			cur = cur->next;
		}
	}
	return *this;
}

List::~List() {
	LIST_VERBOSE_OUT("List:: Destructor called");
	deleteAll();
}

// public methods:
tNode*	List::getHead() const {
	return _head;
}
void*	List::getVal(tNode* node) const {
	return node->val;
}

size_t	List::size() const {
	size_t	size = 0;
	tNode*	cur = _head;
	while (cur != 0) {
		cur = cur->next;
		size++;
	}
	return size;
}

bool	List::isEmpty() const {
	return (_head == 0);
}

tNode*	List::last() const {
	tNode*	end = _head;
	while (end && end->next != 0)
		end = end->next;
	return end;
}

int	List::append(void* value) {
	if (value == 0)
		return FAILURE;
	tNode*	newNode = new tNode;
	if (newNode == 0)
		return(std::cerr << "List::append: Allocation failed!" << std::endl, FAILURE);
	newNode->val = value;
	newNode->next = 0;
	if (isEmpty())
		_head = newNode;
	else
		last()->next = newNode;
	return SUCCESS;
}

void	List::deleteAll() {
	tNode* cur = _head;
	tNode* next;
	if (cur == 0)
		return ;
	while (cur != 0) {
		next = cur->next;
		LIST_VERBOSE_OUT("List:: deleteAll() deleting: " << cur << " | val: " << cur->val)
		delete cur;
		cur = next;
	}
	_head = 0;
}

int		List::remove(void* value) {
	if (value == 0 || isEmpty())
		return FAILURE;
	int	removedNodes = 0;
	tNode*	prev = 0;
	tNode*	cur = _head;
	tNode*	toDelete = 0;
	while (cur != 0) {
		if (cur->val == value) {
			toDelete = cur;
			if (prev == 0)
				_head = cur->next;
			else
				prev->next = cur->next;
			cur = cur->next;
			delete toDelete;
			removedNodes++;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
	if (removedNodes > 0)
		return SUCCESS;
	return FAILURE;
}

tNode*	List::find(void* value) const {
	if (value == 0 || isEmpty())
		return 0;
	tNode*	cur = _head;
	while (cur != 0) {
		if (cur->val == value)
			return cur;
		cur = cur->next;
	}
	return 0;
}

void	List::print() const {
	if (isEmpty()) {
		std::cout << "{Empty List}" << std::endl;
		return ;
	}
	tNode* cur = _head;
	while (cur) {
		std::cout << cur->val << std::endl;
		cur = cur->next;
	}
}
