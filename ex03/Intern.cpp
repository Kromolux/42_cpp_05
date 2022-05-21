/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:13:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 21:00:50 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[Intern] default constructor called " << std::endl << COLOR_DEFAULT;
}

Intern::Intern(Intern const & input)
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[Intern] copy constructor called " << std::endl << COLOR_DEFAULT;
	*this = input;
}

Intern const & Intern::operator=(Intern const & input)
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[Intern] assignment constructor called " << std::endl << COLOR_DEFAULT;
	(void) input;
	return (*this);
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[Intern] deconstructor called " << std::endl << COLOR_DEFAULT;
}

AForm * Intern::makeForm(std::string const & type, std::string const & target) const
{
	std::string const forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	selectedForm = -1;
	AForm * newForm = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (type == forms[i])
		{
			selectedForm = i;
			break;
		}
	}
	switch (selectedForm)
	{
	case 0:
		newForm = new ShrubberyCreationForm(target);
		std::cout << "Intern creates: [ShrubberyCreationForm]\n";
		break;
	case 1:
		newForm = new RobotomyRequestForm(target);
		std::cout << "Intern creates: [RobotomyRequestForm]\n";
		break;
	case 2:
		newForm = new PresidentialPardonForm(target);
		std::cout << "Intern creates: [PresidentialPardonForm]\n";
		break;
	default:
		std::cout << "Intern creates: nothing! The form [" << type << "] does not exist!\n";
		break;
	}
	return (newForm);
}
