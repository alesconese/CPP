#include <vector>
#include <iostream>
#include <algorithm>

void	FJ(std::vector<int> &seq, int lvl)
{
	if (seq.size() / (lvl*2) < 2)
		return;
	for (std::vector<int>::iterator it = seq.begin(); it < seq.end(); it += 2 * lvl)
	{
		if (*it > *(it+1))
			std::swap(*it, *(it+1));
	}

	FJ(seq, lvl++);
}

int	main()
{
	int	arr[] = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};

	std::vector<int>	og_seq;
	for (int i = 0; i < 22; i++)
		og_seq.push_back(arr[i]);

	/* std::cout << og_seq.size() << std::endl;
	for (std::vector<int>::iterator it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n"; */

	FJ(og_seq, 1);
	for (std::vector<int>::iterator it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";

	



	return 0;
}
