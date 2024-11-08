#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	ShrubberyCreationForm scf1("garden");
	Bureaucrat b1("Pep", 42);

	b1.signForm(scf1);
	scf1.execute(b1);
}
