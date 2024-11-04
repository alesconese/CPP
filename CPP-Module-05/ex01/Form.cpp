#include "Form.hpp"

Form::Form() : _name("Unnamed Form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "* Form Default constructor called.\n";
}

Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "* Form constructor called: " << _name << std::endl;
}

Form::~Form()
{
	std::cout << "* Form destructor called: " << _name << std::endl;
}
	
Form::Form(Form const &src) : _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "* Form copy constructor called\n";
	*this = src;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "* Form copy assignment constructor called" << std::endl;
	if (this != &src)
		_signed = src._signed;
	return *this;
}

std::string		Form::getName() const { return _name; }

bool	Form::getSigned() const { return _signed; }

unsigned int	Form::getSignGrade() const { return _sign_grade; }

unsigned int	Form::getExcGrade() const { return _exec_grade; }

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("! ERROR: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("! ERROR: Grade too low");
}

std::ostream	&operator<<(std::ostream &os, Form const &src)
{
	os << "Form " << src.getName() << ". Sign Grade " << src.getSignGrade() << ", Execute Grade " << src.getExcGrade() << ". ";
	if (src.getSigned())
		os << "Signed.";
	else
		os << "Unsigned.";
	return os;
}