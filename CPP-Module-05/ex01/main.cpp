#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Form grade too high * * * * *" << std::endl;
		try
		{
			Form f1("1A", 0, 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f2("2A", 1, 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 2: Form grade too low * * * * *" << std::endl;
		try
		{
			Form f1("1A", 151, 150);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f2("2A", 150, 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 3: Bureaucrat grade too low to sign * * * * *" << std::endl;
		try
		{
			Form f1("1A", 10, 10);
			Bureaucrat b1("Bob", 150);

			std::cout << f1 << std::endl;
			b1.signForm(f1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 4: Form already signed * * * * *" << std::endl;
		try
		{
			Form f1("1A", 10, 10);
			Bureaucrat b1("Bob", 5);
			Bureaucrat b2("Joe", 10);

			std::cout << f1 << std::endl;
			b1.signForm(f1);
			b2.signForm(f1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
