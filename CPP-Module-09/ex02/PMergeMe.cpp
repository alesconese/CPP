#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src) { (void)src; }

PMergeMe &PMergeMe::operator=(const PMergeMe &src)
{
	(void)src;
	return *this;
}

PMergeMe::~PMergeMe() {}

void	PMergeMe::FJ(char **argv)
{
	std::vector<int>	og_vec;
	std::deque<int>		og_deq;

	for (int i = 1; argv[i]; i++)
	{
		char		*endptr;
		long		nbr = std::strtol(argv[i], &endptr, 10);

		if (nbr < 0 || nbr > INT_MAX || *endptr != '\0' || !*argv[i])
			throw std::invalid_argument("arguments must be positive integers.");
		if (std::find(og_vec.begin(), og_vec.end(), static_cast<int>(nbr)) != og_vec.end())
			throw std::invalid_argument("numbers cannot be repeated.");
		
		og_vec.push_back(static_cast<int>(nbr));
		og_deq.push_back(static_cast<int>(nbr));
	}

	//debug. change to subject
	std::cout << "* Original sequence:\n";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	FJ_vec(og_vec);

}

void	PMergeMe::FJ_vec(std::vector<int> &og_vec)
{
	static int	rec_lvl = 1;//debug. delete
	static int	cmp_size = 1;
	
	std::cout << "* Recursion level " << rec_lvl << ":\n";
	if (og_vec.size() / cmp_size < 2)
	{
		std::cout << "NOTHING TO BE DONE\n\n";//debug
		return ;
	}

	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it += cmp_size * 2)
	{
		if (*(it + (cmp_size - 1)) > *(it + cmp_size * 2 - 1))
			for (std::vector<int>::iterator it2 = it; it2 < it + cmp_size; it2++)
				std::iter_swap(it2, it2 + cmp_size);
	}
	//debug
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	rec_lvl++;
	cmp_size *= 2;
	FJ_vec(og_vec);


	

}
