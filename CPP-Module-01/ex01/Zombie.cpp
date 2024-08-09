#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "* A Zombie has come back to life!" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "* Zombie " << this->name << " has come back to life!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "* Zombie " << this->name << " has died (again)..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
