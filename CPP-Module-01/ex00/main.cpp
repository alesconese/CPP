#include "Zombie.hpp"

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

int	main()
{
	Zombie *z1 = newZombie("Paco");

	randomChump("Pepe");
	z1->announce();
	randomChump("Juan");
	delete z1;
}
