/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 06:49:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <limits.h>

//static void	try_catch(void (*f)(void));
static void	test_constructor(void);
static void	print_text(std::string output);

int	main(void)
{
	test_constructor();
	return (0);
}
/*
static void	try_catch(void (*f)(void))
{
	try
	{
		f();
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}
*/
static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}

//*************************************************************************************

static void	test_constructor(void)
{
	print_text("===(STARTING TESTS)===");
	{
		print_text("--> create Intern");

		Intern	someRandomIntern;

		print_text("--> create valid forms");
		
		AForm * form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm * form2 = someRandomIntern.makeForm("shrubbery creation", "Outside");
		AForm * form3 = someRandomIntern.makeForm("presidential pardon", "Heino");

		print_text("--> create invalid form");

		AForm * form4 = someRandomIntern.makeForm("expense reimbursement", "Intern");

		print_text("--> create valid bureaucrat");
		
		Bureaucrat	person1("Hermann", 2);
		std::cout << person1 << std::endl;

		print_text("--> valid sign forms");
		
		person1.signForm(form1);
		person1.signForm(form2);
		person1.signForm(form3);
		
		print_text("--> invalid sign forms");
		person1.signForm(form4);
	
		print_text("--> executing valid forms");
		print_text("--> Test 0");
		person1.executeForm(form1);
		print_text("--> Test 1");
		person1.executeForm(form2);
		print_text("--> Test 2");
		person1.executeForm(form3);
	
		print_text("--> executing invalid form");
		person1.executeForm(form4);
	
		print_text("--> deleting valid forms");

		delete form1;
		delete form2;
		delete form3;
	}
}
