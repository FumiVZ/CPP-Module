#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const &src);
	~MutantStack();
	MutantStack &operator=(MutantStack const &rhs);
	T &operator[](int index);
	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{

}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
T &MutantStack<T>::operator[](int index)
{
	iterator it = this->begin();
	for (int i = 0; i < index; i++)
		it++;
	return *it;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

#endif