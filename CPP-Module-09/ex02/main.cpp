#include "PMergeMe.hpp"


/*
void	ft_insert(std::vector<int> &og_seq)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	extra;

	std::vector<int>::iterator	og_it = og_seq.begin();
	
	int		cmp_size = 8;
	int		jaco;
	int		inserted = 0;

	std::vector<int>::iterator	insert_pos;
	std::vector<int>::iterator	b_last;
	std::vector<int>::iterator	a_first;

	cmp_size = 4;
	
	//insert bs from pend to main, starting with jacobsthal 3 
	jaco = 2;
	//insert b3 -> {b1,a1,a2}
	b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1)) - 1;
	std::cout << "b_last: " << *b_last << "\n";

	insert_pos = std::upper_bound(main.begin(), main.end(), *b_last);
	std::cout << "insert_pos: " << *insert_pos << "\n";

	main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
	pend.erase(b_last - (cmp_size - 1), b_last + 1);

	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//insert b2 -> {b1,a1,b3}
	b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1) - 1) - 1;
	std::cout << "b_last: " << *b_last << "\n";
	a_first = std::find(main.begin(), main.end(), *(og_seq.begin() + (get_Jacobsthal(jaco) - 1) * cmp_size * 2 - cmp_size));
	std::cout << "a_first: " << *a_first << "\n";
	insert_pos = std::upper_bound(main.begin(), a_first, *b_last);
	std::cout << "insert_pos: " << *insert_pos << "\n";
	main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
	pend.erase(b_last - (cmp_size - 1), b_last + 1);
	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	og_seq = main;
	og_seq.insert(og_seq.end(), extra.begin(), extra.end());
	main.clear();
	pend.clear();
	extra.clear();
	std::cout << "AFTER: ";
	for (og_it = og_seq.begin(); og_it < og_seq.end(); og_it++)
		std::cout << *og_it << " ";
	std::cout << "\n\n";

	//recursion level 2 (elements of 2 numbers)
	std::cout << "* Recursion level 2 (elements of 2 numbers):\n";
	std::cout << "BEFORE: ";
	for (og_it = og_seq.begin(); og_it < og_seq.end(); og_it++)
		std::cout << *og_it << " ";
	std::cout << "\n";

	cmp_size = 2;

	//b1,a1 >> main
	main.insert(main.end(), og_seq.begin(), og_seq.begin() + cmp_size * 2);
	for(og_it = og_seq.begin() + cmp_size * 2; og_it < og_seq.end(); og_it += cmp_size)
	{
		if (og_seq.end() - og_it < cmp_size)
			extra.insert(extra.end(), og_it, og_seq.end());
		else if ((og_it - og_seq.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), og_it, og_it + cmp_size);//bn >> pend
		else
			main.insert(main.end(), og_it, og_it + cmp_size);//an >> main
	}
	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nEXTRA: ";
	for (std::vector<int>::iterator it = extra.begin(); it < extra.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//insert bs from pend to main, starting with jacobsthal 3 
	jaco = 2;
	
	while (!pend.empty())
	{
		inserted = 0;
		while (inserted < (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1)))
		{
			b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1) - inserted) - 1;
			std::cout << "b_last: " << *b_last << "\n";
			a_first = std::find(main.begin(), main.end(), *(og_seq.begin() + (get_Jacobsthal(jaco) - inserted) * cmp_size * 2 - cmp_size));
			std::cout << "a_first: " << *a_first << "\n";
			insert_pos = my_upper_bound(main.begin(), a_first, *b_last, cmp_size);
			if (insert_pos == a_first)
				insert_pos++;
			std::cout << "insert_pos: " << *insert_pos << "\n";
			main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
			pend.erase(b_last - (cmp_size - 1), b_last + 1);
			std::cout << "MAIN: ";
			for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
				std::cout << *it << " ";
			std::cout << "\nPEND: ";
			for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
				std::cout << *it << " ";
			std::cout << "\n\n";
			inserted++;
		}
		jaco++;
	}
	//after finishing jacobsthal 5 insertions there is 1 element left in pend -> segfault
}*/

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "(!) ERROR: Not enough arguments.\n";
		return 1;
	}
	try
	{
		PMergeMe::FJ(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "(!) ERROR: " << e.what() << '\n';
	}

	return 0;
}
