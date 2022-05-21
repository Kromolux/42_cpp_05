/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:45:27 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 14:48:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const & name, int gradeToSign, int gradeToExec) : _name(name), _GradeToSign(gradeToSign), _GradeToExec(gradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[Form] default constructor called " << name << " " << gradeToSign << " " << gradeToExec << std::endl << COLOR_DEFAULT;

	if (gradeToSign > _MINGRADE || gradeToExec > _MINGRADE)
	{
		throw GradeTooLowException();
	}
	if (gradeToSign < _MAXGRADE || gradeToExec < _MAXGRADE)
	{
		throw GradeTooHighException();
	}
	this->_isSigned = false;
}

Form::Form(Form const & input) : _name(input._name + "_copy"), _GradeToSign(input._GradeToSign), _GradeToExec(input._GradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[Form] copy constructor called " << input._name << " " << input._GradeToSign << " " << input._GradeToExec << std::endl << COLOR_DEFAULT;

	*this = input;
}

Form::Form(Form const * input) : _name(input->_name + "_copy"), _GradeToSign(input->_GradeToSign), _GradeToExec(input->_GradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[Form] copy constructor called " << input->_name << " " << input->_GradeToSign << " " << input->_GradeToExec << std::endl << COLOR_DEFAULT;

	*this = *input;
}

Form const & Form::operator=(Form const & input)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[Form] assignment constructor called " << input._name << " " << input._GradeToSign << " " << input._GradeToExec << std::endl << COLOR_DEFAULT;

	this->_isSigned = input._isSigned;
	return (*this);
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[Form] deconstructor called " << _name << " " << _GradeToSign << " " << _GradeToExec << std::endl << COLOR_DEFAULT;
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (this->_GradeToSign);
}

int	Form::getGradeToExec(void) const
{
	return (this->_GradeToExec);
}

void	Form::beSigned(Bureaucrat const & input)
{
	beSigned(&input);
}

void	Form::beSigned(Bureaucrat const * input)
{
	if (this->_isSigned)
		throw FormAlreadySignedException();
	if (input->getGrade() <= this->_GradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & input)
{
	o << &input;
	//o	<< input.getName() << ", Form status: " << (input.getIsSigned() ? "signed" : "unsigned") << " grade to sign: "
	//	<< input.getGradeToSign() << " grade to execute: " << input.getGradeToExec();
	return (o);
}

std::ostream & operator<<(std::ostream & o, Form const * input)
{
	o	<< input->getName() << ", Form status: " << (input->getIsSigned() ? "signed" : "unsigned") << " - grade to sign: "
		<< input->getGradeToSign() << " - grade to execute: " << input->getGradeToExec();
	return (o);
}
