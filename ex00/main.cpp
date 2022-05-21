/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 15:25:41 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <limits.h>

static void	try_catch(void (*f)(void));
static void	test_constructor(void);
static void	test_increment(void);
static void	test_decrement(void);
static void	print_text(std::string output);

int	main(void)
{
	test_constructor();
	test_increment();
	test_decrement();
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

static void	test_constructor(void)
{
	print_text("===(BASIC CONSTRUCTOR TESTS)===");
	
	{
		print_text("\n--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		print_text("--> copy valid bureaucrats");

		Bureaucrat person3(person1);
		std::cout << person3 << std::endl;
		Bureaucrat *person4 = new Bureaucrat(*person2);
		std::cout << person4 << std::endl;

		print_text("--> deleting valid bureaucrats");
		
		delete person2;
		delete person4;
	}
	{
		print_text("--> create invalid bureaucrats");
		try_catch(&invalid_constructor_test0);
		try_catch(&invalid_constructor_test1);
		try_catch(&invalid_constructor_test2);
		try_catch(&invalid_constructor_test3);
		try_catch(&invalid_constructor_test4);
		try_catch(&invalid_constructor_test5);
	}
}

static void	invalid_constructor_test0(void)
{
	Bureaucrat	person1("Invalid0", 0);
	std::cout << person1 << std::endl;
}
static void	invalid_constructor_test1(void)
{
	Bureaucrat	*person2 = new Bureaucrat("Invalid1", -1);
	std::cout << person2 << std::endl;
}
static void	invalid_constructor_test2(void)
{
	Bureaucrat person3("Invalid2", 151);
	std::cout << person3 << std::endl;
}
static void	invalid_constructor_test3(void)
{
	Bureaucrat *person4 = new Bureaucrat("Invalid3", INT_MAX);
	std::cout << person4 << std::endl;
}
static void	invalid_constructor_test4(void)
{
	Bureaucrat	person5("Invalid4", INT_MIN);
	std::cout << person5 << std::endl;
}
static void	invalid_constructor_test5(void)
{
	Bureaucrat	*person6 = new Bureaucrat("Invalid5", 4242);
	std::cout << person6 << std::endl;
}

//*************************************************************************************
static void	invalid_increment_test0(void);

static void	test_increment(void)
{
	print_text("\n===(INCREMENT GRADE TESTS)===");
	
	{
		print_text("--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		print_text("--> increment bureaucrat grades valid");
		person1.incrementGrade();
		std::cout << person1 << std::endl;
		person1.incrementGrade();
		std::cout << person1 << std::endl;

		person2->incrementGrade();
		std::cout << person2 << std::endl;
		person2->incrementGrade();
		std::cout << person2 << std::endl;
		
		print_text("--> deleting valid bureaucrats");

		delete person2;
	}
	{
		print_text("--> increment bureaucrat grades invalid");
		try_catch(&invalid_increment_test0);
	}
}

static void	invalid_increment_test0(void)
{
	Bureaucrat	person1("Otto", 1);
	std::cout << person1 << std::endl;
	person1.incrementGrade();
	person1.incrementGrade();
}

//*************************************************************************************
static void	invalid_decrement_test0(void);

static void	test_decrement(void)
{
	print_text("===(DECREMENT GRADE TESTS)===");
	
	{
		print_text("--> create valid bureaucrats");
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		print_text("--> decrement bureaucrat grades valid");
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;

		person2->decrementGrade();
		std::cout << person2 << std::endl;
		person2->decrementGrade();
		std::cout << person2 << std::endl;
		
		print_text("--> deleting valid bureaucrats");

		delete person2;
	}
	{
		print_text("--> decrement bureaucrat grades invalid");
		try_catch(&invalid_decrement_test0);
	}
}

static void	invalid_decrement_test0(void)
{
	Bureaucrat	person1("Otto", 150);
	std::cout << person1 << std::endl;
	person1.decrementGrade();
	person1.decrementGrade();
}
