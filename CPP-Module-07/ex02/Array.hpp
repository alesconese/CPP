#ifndef ARRAY_HPP
# define ARRAY_HPP

template	<typename T>
class Array
{
	private:
			T				*_arr;
			unsigned int	_size;
	
	public:
			Array();
			Array(unsigned int n);
			~Array();
			Array(Array const &src);
			Array &operator=(Array const &src);
};

#endif