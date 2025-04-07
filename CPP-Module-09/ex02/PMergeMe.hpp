#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <climits>
# include <cmath>

class PMergeMe
{
	private:
			PMergeMe();
			PMergeMe(const PMergeMe &src);
			PMergeMe &operator=(const PMergeMe &src);
			~PMergeMe();

			static void	FJ_vec(std::vector<int> &og_vec);

			static int	get_Jacobsthal(int k);
			static std::vector<int>::iterator	my_upper_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, int cmp_size);

	public:
			static void	FJ(char **argv);
};

#endif
