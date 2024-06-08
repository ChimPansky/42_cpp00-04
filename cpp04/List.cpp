#include "List.hpp"
#include <iostream>

// constructors, copy assignment operator overload and destructor:
List::List()
	: _head(0) {}

List::List(const List& other)
	: _head(0) {
		*this = other;
}

List&	List::operator=(const List& other) {
	if (this == &other)
		return *this;
	if (!lIsEmpty())
		_listDeleteAll();
	if (!other.lIsEmpty()) {
		tNode* cur = other._head;
		while (cur) {
			lAppend(cur->val);
			cur = cur->next;
		}
	}
	return *this;
}

List::~List() {
	_listDeleteAll();
}

// public methods:
size_t	List::lSize() const {
	size_t	size = 0;
	tNode*	cur = _head;
	while (cur != 0) {
		cur = cur->next;
		size++;
	}
	return size;
}

bool	List::lIsEmpty() const {
	return (_head == 0);
}

tNode*	List::lLast() const {
	tNode*	end = _head;
	while (end && end->next != 0)
		end = end->next;
	return end;
}

int	List::lAppend(void* value) {
	if (value == 0)
		return FAILURE;
	tNode*	newNode = new tNode;
	if (newNode == 0)
		return(std::cerr << "List::lAppend: Allocation failed!" << std::endl, FAILURE);
	newNode->val = value;
	newNode->next = 0;
	if (lIsEmpty())
		_head = newNode;
	else
		lLast()->next = newNode;
	return SUCCESS;
}

// private methods:
void	List::_listDeleteAll() {
	tNode* cur = _head;
	tNode* next;
	if (cur == 0)
		return ;
	while (cur != 0) {
		next = cur->next;
		delete cur;
		cur = next;
	}
}

int		List::lRemove(void* value) {
	if (value == 0 || lIsEmpty())
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

void	List::lPrint() const {
	if (lIsEmpty()) {
		std::cout << "{Empty List}" << std::endl;
		return ;
	}
	tNode* cur = _head;
	while (cur) {
		std::cout << cur->val << std::endl;
		cur = cur->next;
	}
}
