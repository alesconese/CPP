#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int		N = 5;
	Zombie *h1 = zombieHorde(N, "Paco");

	for (int i = 0; i < N; i++)
		h1[i].announce();
	delete [] h1;
}
