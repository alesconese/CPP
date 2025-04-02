#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <climits>


class PMergeMe
{
	private:
			PMergeMe();
			PMergeMe(const PMergeMe &src);
			PMergeMe &operator=(const PMergeMe &src);
			~PMergeMe();

			static void	FJ_vec(std::vector<int> &og_vec);

	public:
			static void	FJ(char **argv);
};

#endif
