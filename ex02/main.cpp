/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 20:03:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <limits.h>

static void	try_catch(void (*f)(void));
static void	test_constructor(void);
static void	test_sign(void);
static void	test_execution(void);
static void	print_text(std::string output);

int	main(void)
{
	test_constructor();
	test_sign();
	test_execution();
	return (0);
}

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

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}

//*************************************************************************************

static void	test_constructor(void)
{
	print_text("===(BASIC CONSTRUCTOR TESTS)===");
	{
		print_text("--> create valid forms");

		ShrubberyCreationForm	*form1 = new ShrubberyCreationForm("Garden");
		std::cout << form1 << std::endl;
		ShrubberyCreationForm	*form2 = new ShrubberyCreationForm("Park");
		std::cout << form2 << std::endl;
		RobotomyRequestForm		form3("Miningstation");
		std::cout << form3 << std::endl;
		PresidentialPardonForm	form4("Seth");
		std::cout << form4 << std::endl;

		print_text("--> deleting valid forms");

		delete form1;
		delete form2;
	}
}

//*************************************************************************************
static void	invalid_sign_test0(void);
static void	invalid_sign_test1(void);
static void	invalid_sign_test2(void);

static void	test_sign(void)
{
	print_text("===(SIGN FORM TESTS)===");
	
	{
		print_text("--> create valid forms");

		ShrubberyCreationForm	*form1 = new ShrubberyCreationForm("Garden");
		std::cout << form1 << std::endl;
		ShrubberyCreationForm	*form2 = new ShrubberyCreationForm("Park");
		std::cout << form2 << std::endl;
		RobotomyRequestForm		form3("Miningstation");
		std::cout << form3 << std::endl;
		PresidentialPardonForm	form4("Seth");
		std::cout << form4 << std::endl;
	
		print_text("--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 25);
		std::cout << person2 << std::endl;

		print_text("--> copy valid bureaucrats");

		Bureaucrat person3(person1);
		std::cout << person3 << std::endl;
		Bureaucrat *person4 = new Bureaucrat(*person2);
		std::cout << person4 << std::endl;

		print_text("--> valid sign forms");

		person1.signForm(form1);
		std::cout << form1 << std::endl;

		person2->signForm(form2);
		std::cout << form2 << std::endl;
		
		person3.signForm(form3);
		std::cout << form3 << std::endl;

		person4->signForm(form4);
		std::cout << form4 << std::endl;

		print_text("--> deleting valid bureaucrats");
		
		delete person2;
		delete person4;
		
		print_text("--> deleting valid Forms");

		delete form1;
		delete form2;
	}
	{
		print_text("--> invalid sign Forms");
		try_catch(&invalid_sign_test0);
		try_catch(&invalid_sign_test1);
		try_catch(&invalid_sign_test2);
	}
}

static void	invalid_sign_test0(void)
{
	AForm	*form1 = new ShrubberyCreationForm("Garden");
	std::cout << form1 << std::endl;
	Bureaucrat	person1("Otto", 150);
	std::cout << person1 << std::endl;
	person1.signForm(form1);
	delete form1;
}
static void	invalid_sign_test1(void)
{
	AForm	*form2 = new RobotomyRequestForm("Miningstation");
	std::cout << form2 << std::endl;
	Bureaucrat	*person2 = new Bureaucrat("Ralf", 146);
	std::cout << person2 << std::endl;
	person2->signForm(form2);
	delete form2;
	delete person2;
}
static void	invalid_sign_test2(void)
{
	AForm	*form3 = new PresidentialPardonForm("Seth");
	std::cout << form3 << std::endl;
	Bureaucrat	person1("Peter", 55);
	std::cout << person1 << std::endl;
	person1.signForm(form3);
	person1.signForm(form3);
	delete form3;
}

//*************************************************************************************
static void	invalid_exec_test0(void);
static void	invalid_exec_test1(void);
static void	invalid_exec_test2(void);

static void	test_execution(void)
{
	print_text("===(EXECUTION FORM TESTS)===");
	{
		print_text("--> create valid forms");

		ShrubberyCreationForm	*form1 = new ShrubberyCreationForm("Garden");
		std::cout << form1 << std::endl;
		ShrubberyCreationForm	*form2 = new ShrubberyCreationForm("Park");
		std::cout << form2 << std::endl;
		RobotomyRequestForm		form3("Miningstation");
		std::cout << form3 << std::endl;
		PresidentialPardonForm	form4("Seth");
		std::cout << form4 << std::endl;
	
		print_text("--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 5);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 5);
		std::cout << person2 << std::endl;

		print_text("--> copy valid bureaucrats");

		Bureaucrat person3(person1);
		std::cout << person3 << std::endl;
		Bureaucrat *person4 = new Bureaucrat(*person2);
		std::cout << person4 << std::endl;

		print_text("--> valid sign forms");

		person1.signForm(form1);
		std::cout << form1 << std::endl;

		person2->signForm(form2);
		std::cout << form2 << std::endl;
		
		person3.signForm(form3);
		std::cout << form3 << std::endl;

		person4->signForm(form4);
		std::cout << form4 << std::endl;

		print_text("--> executing valid forms");

		person1.executeForm(form1);
		form4.execute(person2);
		person3.executeForm(form3);
		print_text("--> deleting valid bureaucrats");
		
		delete person2;
		delete person4;
		
		print_text("--> deleting valid Forms");

		delete form1;
		delete form2;
	}
	{
		print_text("--> invalid execution Forms");
		try_catch(&invalid_exec_test0);
		try_catch(&invalid_exec_test1);
		try_catch(&invalid_exec_test2);
	}
}

static void	invalid_exec_test0(void)
{
	AForm	*form1 = new ShrubberyCreationForm("Garden");
	std::cout << form1 << std::endl;
	Bureaucrat	person1("Otto", 138);
	std::cout << person1 << std::endl;
	person1.executeForm(form1);
	person1.signForm(form1);
	person1.executeForm(form1);
	delete form1;
}
static void	invalid_exec_test1(void)
{
	AForm	*form2 = new RobotomyRequestForm("Park");
	std::cout << form2 << std::endl;
	Bureaucrat	*person2 = new Bureaucrat("Ralf", 46);
	std::cout << person2 << std::endl;
	form2->execute(person2);
	person2->signForm(form2);
	form2->execute(person2);
	delete form2;
	delete person2;
}
static void	invalid_exec_test2(void)
{
	AForm	*form3 = new PresidentialPardonForm("Seth");
	std::cout << form3 << std::endl;
	Bureaucrat	person1("Peter", 25);
	std::cout << person1 << std::endl;
	person1.signForm(form3);
	person1.executeForm(form3);
	delete form3;
}
