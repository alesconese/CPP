#include "Iter.hpp"

void	add(int &x)
{
	x += 1;
}

int	main()
{
	int	iarr[5] = {23, 42, 101, 9, 11};
	
	std::cout << "* Original: { ";
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i] << " ";
	std::cout << "}" << std::endl;

	::iter<int>(iarr, 5, add);
	
	std::cout << "* Modified: { ";
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i] << " ";
	std::cout << "}" << std::endl;

	return 0;
}