#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
public:
	Array();
	Array(Array const &other);
	Array &operator=(Array const &other);
	Array(unsigned int size);
	T &operator[](unsigned int i);
		~Array();
	unsigned int size() const;
	T &get(unsigned int i) const;

private:
	T *_array;
	unsigned int _size;
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const Array<U> &array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
	{
		os << array.get(i) << " ";
	}
	return os;
}

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Array default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << "Array constructor" << std::endl;
}
template <typename T>
Array<T>::Array(Array const &other) : _array(new T[other._size]), _size(other._size)
{
	std::cout << "Array copy constructor" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}
template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor" << std::endl;
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	std::cout << "Array operator=" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
	{
		throw std::out_of_range("Array index out of range");
	}
	return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
T &Array<T>::get(unsigned int i) const
{
	if (i >= _size)
	{
		throw std::out_of_range("Array index out of range");
	}
	return _array[i];
}

#endif