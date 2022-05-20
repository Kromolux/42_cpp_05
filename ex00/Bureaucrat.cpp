/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:30:07 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 21:57:32 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, unsigned int & grade) : _name(name)
{
	if (grade > _MinGrade)
	{
		throw GradeTooLowException();
	}
	if (grade < _MaxGrade)
	{
		throw GradeTooHighException();
	}
	_grade = grade;
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] default constructor called" << std::endl << COLOR_DEFAULT;
}

Bureaucrat::Bureaucrat(Bureaucrat const & input) : _name(input._name)
{
	*this = input;
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] copy constructor called" << std::endl << COLOR_DEFAULT;
}

Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & input)
{
	this->_grade = input._grade;
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] assignment constructor called" << std::endl << COLOR_DEFAULT;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Bureaucrat] deconstructor called" << std::endl << COLOR_DEFAULT;
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == this->_MaxGrade)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == this->_MinGrade)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input)
{
	o << input.getName() << ", bureaucrat grade " << input.getGrade() << std::endl;
	return (o);
}
