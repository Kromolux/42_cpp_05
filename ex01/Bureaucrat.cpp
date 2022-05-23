/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:30:07 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 11:16:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] default constructor called " << name << " " << grade << std::endl << COLOR_DEFAULT;

	if (grade > _MINGRADE)
	{
		throw GradeTooLowException();
	}
	if (grade < _MAXGRADE)
	{
		throw GradeTooHighException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & input) : _name(input._name + "_copy")
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] copy constructor called " << input._name << " " << input._grade << std::endl << COLOR_DEFAULT;

	*this = input;
}

Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & input)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] assignment constructor called " << input._name << " " << input._grade << std::endl << COLOR_DEFAULT;

	this->_grade = input._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] deconstructor called " << _name << " " << _grade << std::endl << COLOR_DEFAULT;
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] incrementGrade called " << _name << " " << _grade << std::endl << COLOR_DEFAULT;
	if (this->_grade == this->_MAXGRADE)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] decrementGrade called " << _name << " " << _grade << std::endl << COLOR_DEFAULT;
	if (this->_grade == this->_MINGRADE)
		throw GradeTooLowException();
	this->_grade++;
}


void	Bureaucrat::signForm(Form & form) const
{
	signForm(&form);
}

void	Bureaucrat::signForm(Form * form) const
{
	try
	{
		form->beSigned(*this);
		std::cout << COLOR_GREEN << this->_name << " signed " << form->getName() << "\n" << COLOR_DEFAULT;
	}
	catch (std::exception & error)
	{
		std::cout << COLOR_RED << this->_name << " couldn't sign " << form->getName() << " because " << error.what() << "\n" <<COLOR_DEFAULT;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input)
{
	o << input.getName() << ", bureaucrat grade " << input.getGrade();
	return (o);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const * input)
{
	o << input->getName() << ", bureaucrat grade " << input->getGrade();
	return (o);
}
