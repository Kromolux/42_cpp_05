/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:11:49 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 21:59:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm(target, _GRADE_TO_SIGN, _GRADE_TO_EXCE), _FormType("ShrubberyCreationForm")
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[ShrubberyCreationForm] default constructor called " << std::endl << COLOR_DEFAULT;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & input) : AForm(input), _FormType("ShrubberyCreationForm")
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[ShrubberyCreationForm] copy constructor called " << std::endl << COLOR_DEFAULT;

	*this = input;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & input)
{

	if (DEBUG)
		std::cout << COLOR_CYAN << "[ShrubberyCreationForm] assignment constructor called " << std::endl << COLOR_DEFAULT;
	return (input);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << COLOR_CYAN << "[ShrubberyCreationForm] deconstructor called " << std::endl << COLOR_DEFAULT;
}

std::string const & ShrubberyCreationForm::getFormType(void) const
{
	return (this->_FormType);
}

void	ShrubberyCreationForm::validExecution(Bureaucrat const & executor) const
{
	std::string	const filename = (this->getName() + "_shrubbery");
	std::ofstream	output_file(filename.c_str());
	if (!output_file.is_open())
		throw CantAccessFileException();
	output_file << "               ,@@@@@@@,\n";
	output_file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	output_file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	output_file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	output_file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	output_file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	output_file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	output_file << "       |o|        | |         | |\n";
	output_file << "       |.|        | |         | |\n";
	output_file << "     \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	output_file.close();
	std::cout << executor.getName() << " executed " << this->getName() << " " << this->_FormType << "\n";
}
