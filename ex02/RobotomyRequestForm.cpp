/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:26:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 06:54:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm(target, _GRADE_TO_SIGN, _GRADE_TO_EXCE), _FormType("RobotomyRequestForm")
{
	if (DEBUG)
		std::cout << COLOR_WHITE << "[RobotomyRequestForm] default constructor called " << std::endl << COLOR_DEFAULT;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & input) : AForm(input), _FormType("RobotomyRequestForm")
{
	if (DEBUG)
		std::cout << COLOR_WHITE << "[RobotomyRequestForm] copy constructor called " << std::endl << COLOR_DEFAULT;

	*this = input;
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & input)
{

	if (DEBUG)
		std::cout << COLOR_WHITE << "[RobotomyRequestForm] assignment constructor called " << std::endl << COLOR_DEFAULT;
	return (input);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << COLOR_WHITE << "[RobotomyRequestForm] deconstructor called " << std::endl << COLOR_DEFAULT;
}

std::string const & RobotomyRequestForm::getFormType(void) const
{
	return (this->_FormType);
}

void	RobotomyRequestForm::validExecution(Bureaucrat const & executor) const
{
	srand(time(NULL));
	std::cout << "ddrrrr bbrrrzzz rzzddr brrddzzzs ggrrrrrrr  zzz fffssss\n";
	if (rand() % 2 == 1)
	{
		std::cout << COLOR_GREEN << this->getName() << " has been robotomized successfully!\n";
	}
	else
	{
		std::cout << COLOR_RED << this->getName() << " attempt to beeing robotomize failed!\n";
	}
	std::cout << COLOR_GREEN << executor.getName() << " executed " << this->getName() << " " << this->_FormType << "\n" << COLOR_DEFAULT;
}
