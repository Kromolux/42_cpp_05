/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 06:43:36 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <limits.h>

static void	try_catch(void (*f)(void));
static void	test_constructor(void);
static void	test_sign(void);
static void	print_text(std::string output);

int	main(void)
{
	test_constructor();
	test_sign();
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
static void	invalid_constructor_test0(void);
static void	invalid_constructor_test1(void);
static void	invalid_constructor_test2(void);
static void	invalid_constructor_test3(void);
static void	invalid_constructor_test4(void);
static void	invalid_constructor_test5(void);
static void	invalid_constructor_test6(void);
static void	invalid_constructor_test7(void);
static void	invalid_constructor_test8(void);
static void	invalid_constructor_test9(void);
static void	invalid_constructor_test10(void);
static void	invalid_constructor_test11(void);

static void	test_constructor(void)
{
	print_text("===(BASIC CONSTRUCTOR TESTS)===");
	
	{
		print_text("--> create valid forms");

		Form	form1("Driver's license application", 47, 83);
		std::cout << form1 << std::endl;
		Form	*form2 = new Form("Identity card application", 80, 120);
		std::cout << form2 << std::endl;

		print_text("--> copy valid forms");

		Form	form3(form1);
		std::cout << form3 << std::endl;
		Form	*form4 = new Form(form2);
		std::cout << form4 << std::endl;

		print_text("--> deleting valid forms");
		
		delete form2;
		delete form4;
	}
	{
		print_text("--> create invalid forms");
		try_catch(&invalid_constructor_test0);
		try_catch(&invalid_constructor_test1);
		try_catch(&invalid_constructor_test2);
		try_catch(&invalid_constructor_test3);
		try_catch(&invalid_constructor_test4);
		try_catch(&invalid_constructor_test5);
		try_catch(&invalid_constructor_test6);
		try_catch(&invalid_constructor_test7);
		try_catch(&invalid_constructor_test8);
		try_catch(&invalid_constructor_test9);
		try_catch(&invalid_constructor_test10);
		try_catch(&invalid_constructor_test11);
	}
}

static void	invalid_constructor_test0(void)
{
	Form	form1("Invalid0", 0, 1);
	std::cout << form1 << std::endl;
}
static void	invalid_constructor_test1(void)
{
	Form	*form2 = new Form("Invalid1", -1 , 23);
	std::cout << form2 << std::endl;
}
static void	invalid_constructor_test2(void)
{
	Form form3("Invalid2", 151 , 1);
	std::cout << form3 << std::endl;
}
static void	invalid_constructor_test3(void)
{
	Form *form4 = new Form("Invalid3", INT_MAX, 23);
	std::cout << form4 << std::endl;
}
static void	invalid_constructor_test4(void)
{
	Form	form5("Invalid4", INT_MIN, 42);
	std::cout << form5 << std::endl;
}
static void	invalid_constructor_test5(void)
{
	Form	*form6 = new Form("Invalid5", 4242 , 42);
	std::cout << form6 << std::endl;
}

static void	invalid_constructor_test6(void)
{
	Form	form1("Invalid6", 1, 0);
	std::cout << form1 << std::endl;
}
static void	invalid_constructor_test7(void)
{
	Form	*form2 = new Form("Invalid7", 23, -1);
	std::cout << form2 << std::endl;
}
static void	invalid_constructor_test8(void)
{
	Form form3("Invalid8", 1, 151);
	std::cout << form3 << std::endl;
}
static void	invalid_constructor_test9(void)
{
	Form *form4 = new Form("Invalid9", 23, INT_MAX);
	std::cout << form4 << std::endl;
}
static void	invalid_constructor_test10(void)
{
	Form	form5("Invalid10", 42, INT_MIN);
	std::cout << form5 << std::endl;
}
static void	invalid_constructor_test11(void)
{
	Form	*form6 = new Form("Invalid11", 42 , 4242);
	std::cout << form6 << std::endl;
}

//*************************************************************************************
static void	invalid_sign_test0(void);
static void	invalid_sign_test1(void);
static void	invalid_sign_test2(void);

static void	test_sign(void)
{
	print_text("===(SIGN FORM TESTS)===");
	
	{
		print_text("--> create valid Forms");
		
		Form	form1("Driver's license application", 47, 83);
		std::cout << form1 << std::endl;
		Form	*form2 = new Form("Identity card application", 80, 120);
		std::cout << form2 << std::endl;

		print_text("--> copy valid forms");

		Form	form3(form1);
		std::cout << form3 << std::endl;
		Form	*form4 = new Form(form2);
		std::cout << form4 << std::endl;

		Form	form5(form3);
		std::cout << form5 << std::endl;
		Form	*form6 = new Form(form4);
		std::cout << form6 << std::endl;

		print_text("--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
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
		
		person1.signForm(form6);
		std::cout << form6 << std::endl;

		person4->signForm(form5);
		std::cout << form5 << std::endl;

		print_text("--> deleting valid bureaucrats");
		
		delete person2;
		delete person4;
		
		print_text("--> deleting valid Forms");

		delete form2;
		delete form4;
		delete form6;
	}
	{
		print_text("--> invalid sign Forms");
		print_text("--> Test 0");
		try_catch(&invalid_sign_test0);
		print_text("--> Test 1");
		try_catch(&invalid_sign_test1);
		print_text("--> Test 2");
		try_catch(&invalid_sign_test2);
	}
}

static void	invalid_sign_test0(void)
{
	Form	form1("Driver's license application", 47, 83);
	std::cout << form1 << std::endl;
	Bureaucrat	person1("Otto", 150);
	std::cout << person1 << std::endl;
	person1.signForm(form1);
}
static void	invalid_sign_test1(void)
{
	Form	*form2 = new Form("Identity card application", 80, 120);
	std::cout << form2 << std::endl;
	Bureaucrat	*person2 = new Bureaucrat("Ralf", 129);
	std::cout << person2 << std::endl;
	person2->signForm(form2);
	delete form2;
	delete person2;
}
static void	invalid_sign_test2(void)
{
	Form	form1("Driver's license application", 47, 83);
	std::cout << form1 << std::endl;
	Bureaucrat	person1("Otto", 23);
	std::cout << person1 << std::endl;
	person1.signForm(form1);
	person1.signForm(form1);
}