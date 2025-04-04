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

	clock_t	start = clock();
	FJ_vec(og_vec);
	clock_t	end = clock();

	//debug. check if sorted
	for (std::vector<int>::iterator it = og_vec.begin() + 1; it < og_vec.end(); it++)
	{
		if (*it < *(it - 1))
		{
			std::cout << "(!) ERROR: Sequence is not sorted.\n";
			return ;
		}
	}

	std::cout << "* Sorted sequence:\n";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	std::cout << "* Time taken to sort the sequence: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us\n\n";

}

void	PMergeMe::FJ_vec(std::vector<int> &og_vec)
{
	static int	rec_lvl = 1;//debug. delete
	static int	cmp_size = 1;
	
	std::cout << "* Recursion level " << rec_lvl << ":\n";
	if (og_vec.size() / cmp_size < 2)
	{
		std::cout << "(!) not enough numbers to make a pair\n\n";//debug
		return ;
	}

	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it += cmp_size * 2)
	{
		if (og_vec.end() - it < cmp_size * 2)
			break ;
		if (*(it + (cmp_size - 1)) > *(it + cmp_size * 2 - 1))
			for (std::vector<int>::iterator it2 = it; it2 < it + cmp_size; it2++)
				std::iter_swap(it2, it2 + cmp_size);
	}
	//debug
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	rec_lvl++; //debug. delete
	cmp_size *= 2;
	FJ_vec(og_vec);
	cmp_size /= 2;
	rec_lvl--; //debug. delete

	//merge insert with jacobsthal optimization
	//start at last recursion level that was able to make a pair
	//can have 2 or 3 pairs and may or may not have extra elements

	std::cout << "* Recursion level " << rec_lvl << ":\n";
	if (og_vec.size() / cmp_size < 2)
	{
		std::cout << "(!) not enough numbers to make a pair\n\n";//debug
		return ;
	}

	std::cout << "BEFORE: ";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	//initialize main with {b1,a1..an}, pend with {b2..bn}, extra with non-participating
	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	extra;

	//move first 2 elements to main (b1,a1)
	main.insert(main.end(), og_vec.begin(), og_vec.begin() + cmp_size * 2);

	//move rest of elements to pend (odd elements / b's) and main (even elements / a's)
	//if not enough numbers for a full element, move to extra
	for (std::vector<int>::iterator it = og_vec.begin() + cmp_size * 2; it < og_vec.end(); it += cmp_size)
	{
		if (og_vec.end() - it < cmp_size)
			extra.insert(extra.end(), it, og_vec.end());//if not enough numbers for an element >> extra
		else if ((it - og_vec.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), it, it + cmp_size);//bn >> pend
		else
			main.insert(main.end(), it, it + cmp_size);//an >> main
	}

	std::cout << "main: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\npend: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nextra: ";
	for (std::vector<int>::iterator it = extra.begin(); it < extra.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	
	//insertion from pend in reeverse order, using binary search
	//needs jacobsthal optimization!!
	while (!pend.empty())
	{
		std::cout << "b_last: " << *(pend.end() - 1) << "\n";
		std::vector<int>::iterator	insert_pos = my_upper_bound(main.begin(), main.end(), *(pend.end() - 1), cmp_size);
		if (insert_pos != main.end())
			insert_pos -= (cmp_size - 1);
		std::cout << "insert_pos: " << *insert_pos << "\n";
		main.insert(insert_pos, pend.end() - cmp_size, pend.end());
		pend.erase(pend.end() - cmp_size, pend.end());
	}

	og_vec = main;
	og_vec.insert(og_vec.end(), extra.begin(), extra.end());
	
	std::cout << "AFTER: ";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

std::vector<int>::iterator	PMergeMe::my_upper_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, int cmp_size)
{
	std::vector<int>::iterator low = first + (cmp_size - 1);
	std::vector<int>::iterator high = last - 1;

	if (value > *high)
		return last; // Value is greater than the largest element

	while (low < high)
	{
		std::vector<int>::iterator mid = low + ((std::distance(low, high) / cmp_size) / 2) * cmp_size; // 0

		if (*mid < value)
			low = mid + cmp_size; // Continue searching in the upper half
		else
			high = mid; // Continue in the lower half
		
	}

	return low; // Return position of upper bound
}
