#include "Array.hpp"

template <class T> Array<T>::Array()
{
	std::cout << "* Array default constructor called" << std::endl;
	_size = 0;
	_arr = new T[0];
}

template <class T> Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "* Array constructor called" << std::endl;
}

