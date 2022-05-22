/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:29:17 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 06:50:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm(target, _GRADE_TO_SIGN, _GRADE_TO_EXCE), _FormType("PresidentialPardonForm")
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[PresidentialPardonForm] default constructor called " << std::endl << COLOR_DEFAULT;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & input) : AForm(input), _FormType("PresidentialPardonForm")
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[PresidentialPardonForm] copy constructor called " << std::endl << COLOR_DEFAULT;

	*this = input;
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & input)
{

	if (DEBUG)
		std::cout << COLOR_BLUE << "[PresidentialPardonForm] assignment constructor called " << std::endl << COLOR_DEFAULT;
	return (input);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[PresidentialPardonForm] deconstructor called " << std::endl << COLOR_DEFAULT;
}

std::string const & PresidentialPardonForm::getFormType(void) const
{
	return (this->_FormType);
}

void	PresidentialPardonForm::validExecution(Bureaucrat const & executor) const
{
	std::cout << COLOR_GREEN << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
	std::cout << executor.getName() << " executed " << this->getName() << " " << this->_FormType << "\n" << COLOR_DEFAULT;
}

