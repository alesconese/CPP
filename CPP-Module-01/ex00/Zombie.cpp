#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "* Zombie " << _name << " has come back to life!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "* Zombie " << _name << " has died (again)..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
