/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:45:27 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 18:30:11 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExec) : _name(name), _GradeToSign(gradeToSign), _GradeToExec(gradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[AForm] default constructor called " << name << " " << gradeToSign << " " << gradeToExec << std::endl << COLOR_DEFAULT;

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

AForm::AForm(AForm const & input) : _name(input._name + "_copy"), _GradeToSign(input._GradeToSign), _GradeToExec(input._GradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[AForm] copy constructor called " << input._name << " " << input._GradeToSign << " " << input._GradeToExec << std::endl << COLOR_DEFAULT;

	*this = input;
}

AForm::AForm(AForm const * input) : _name(input->_name + "_copy"), _GradeToSign(input->_GradeToSign), _GradeToExec(input->_GradeToExec)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[AForm] copy constructor called " << input->_name << " " << input->_GradeToSign << " " << input->_GradeToExec << std::endl << COLOR_DEFAULT;

	*this = *input;
}

AForm const & AForm::operator=(AForm const & input)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[AForm] assignment constructor called " << input._name << " " << input._GradeToSign << " " << input._GradeToExec << std::endl << COLOR_DEFAULT;

	this->_isSigned = input._isSigned;
	return (*this);
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << COLOR_ORANGE << "[AForm] deconstructor called " << _name << " " << _GradeToSign << " " << _GradeToExec << std::endl << COLOR_DEFAULT;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		executor.executeFromForm(*this);
	}
	catch(std::exception & error)
	{
		std::cout << COLOR_RED << executor.getName() << " couldn't execute " << this->_name << " " << this->getFormType() << " because " << error.what() << "\n" <<COLOR_DEFAULT;
	}
}

void	AForm::executeFromBureaucrat(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_GradeToExec)
		throw GradeTooLowException();
	validExecution(executor);
}

void	AForm::execute(Bureaucrat const * executor) const
{
	execute(*executor);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_GradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return (this->_GradeToExec);
}

void	AForm::beSigned(Bureaucrat const & input)
{
	AForm::beSigned(&input);
}

void	AForm::beSigned(Bureaucrat const * input)
{
	if (this->_isSigned)
		throw FormAlreadySignedException();
	if (input->getGrade() <= this->_GradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm const & input)
{
	o << &input;
	//o	<< input.getName() << ", AForm status: " << (input.getIsSigned() ? "signed" : "unsigned") << " grade to sign: "
	//	<< input.getGradeToSign() << " grade to execute: " << input.getGradeToExec();
	return (o);
}

std::ostream & operator<<(std::ostream & o, AForm const * input)
{
	o	<< input->getName() << ", " << input->getFormType() << " status: " << (input->getIsSigned() ? "signed" : "unsigned") << " - grade to sign: "
		<< input->getGradeToSign() << " - grade to execute: " << input->getGradeToExec();
	return (o);
}
