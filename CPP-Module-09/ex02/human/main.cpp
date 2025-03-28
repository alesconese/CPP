#include <vector>
#include <iostream>
#include <algorithm>

void	ft_pairs(std::vector<int> &og_seq)
{
	std::vector<int>::iterator	it;

	std::cout << "* * * PAIRS * * *\n";
	//Recursion level 1
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		it += 2;
	}
	std::cout << "* Recursion level 1 (2 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 2
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 4)
			break;
		if (*(it + 1) > *(it + 3))
		{
			std::iter_swap(it, it + 2);
			std::iter_swap(it + 1, it + 3);
		}
		it += 4;
	}
	std::cout << "* Recursion level 2 (4 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 3
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 8)
			break;
		if (*(it + 3) > *(it + 7))
		{
			std::iter_swap(it, it + 4);
			std::iter_swap(it + 1, it + 5);
			std::iter_swap(it + 2, it + 6);
			std::iter_swap(it + 3, it + 7);
		}
		it += 8;
	}
	std::cout << "* Recursion level 3 (8 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 4
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 16)
			break;
		if (*(it + 7) > *(it + 15))
		{
			std::iter_swap(it, it + 8);
			std::iter_swap(it + 1, it + 9);
			std::iter_swap(it + 2, it + 10);
			std::iter_swap(it + 3, it + 11);
			std::iter_swap(it + 4, it + 12);
			std::iter_swap(it + 5, it + 13);
			std::iter_swap(it + 6, it + 14);
			std::iter_swap(it + 7, it + 15);
		}
		it += 16;
	}
	std::cout << "* Recursion level 4 (16 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

void	ft_insert(std::vector<int> &og_seq)
{
	std::vector<int>	main;
	std::vector<int>	pend;

	std::vector<int>::iterator	it = og_seq.begin();

	std::cout << "* * * INSERTION * * *\n";
	//recursion level 4
	//nothing to do?
	std::cout << "* Recursion level 4 (16 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//recursion level 3
	it = og_seq.begin();
	main.insert(main.end(), it, it + 4);//b1
	it += 4;
	main.insert(main.end(), it, it + 4);//a1
	it += 4;
	pend.insert(pend.end(), it, it + 4);//b2
	it += 4;
	main.insert(main.end(), it, it + 4);//a2
	it += 4;
	pend.insert(pend.end(), it, it + 4);//b3
	
	
	
	og_seq = main;
	main.clear();
	pend.clear();
	std::cout << "* Recursion level 3 (8 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

int	main()
{
	int	arr[] = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};

	std::vector<int>	og_seq;

	for (int i=0; i<22; i++)
		og_seq.push_back(arr[i]);

	std::cout << "* Original sequence:\n";
	for (std::vector<int>::iterator it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	ft_pairs(og_seq);

	ft_insert(og_seq);
	

	return 0;
}