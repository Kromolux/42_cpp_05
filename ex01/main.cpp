/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 10:28:37 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <limits.h>

static void	try_catch(void (*f)(void));
static void	test_constructor(void);
static void	test_increment(void);
static void	test_decrement(void);

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

//*************************************************************************************
static void	invalid_constructor_test0(void);
static void	invalid_constructor_test1(void);
static void	invalid_constructor_test2(void);
static void	invalid_constructor_test3(void);
static void	invalid_constructor_test4(void);
static void	invalid_constructor_test5(void);

static void	test_constructor(void)
{
	std::cout << COLOR_YELLOW << "\n===(BASIC CONSTRUCTOR TESTS)===\n\n" << COLOR_DEFAULT;
	
	{
		std::cout << "\n--> create valid bureaucrats\n";
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		std::cout << "\n--> copy valid bureaucrats\n";

		Bureaucrat person3(person1);
		std::cout << person3 << std::endl;
		Bureaucrat *person4 = new Bureaucrat(*person2);
		std::cout << person4 << std::endl;

		std::cout << "\n--> deleting valid bureaucrats\n";
		
		delete person2;
		delete person4;
	}
	{
		std::cout << "\n--> create invalid bureaucrats\n";
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
	std::cout << COLOR_YELLOW << "\n===(INCREMENT GRADE TESTS)===\n\n" << COLOR_DEFAULT;
	
	{
		std::cout << "\n--> create valid bureaucrats\n";
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		std::cout << "\n--> increment bureaucrat grades valid\n";
		person1.incrementGrade();
		std::cout << person1 << std::endl;
		person1.incrementGrade();
		std::cout << person1 << std::endl;

		person2->incrementGrade();
		std::cout << person2 << std::endl;
		person2->incrementGrade();
		std::cout << person2 << std::endl;
		
		std::cout << "\n--> deleting valid bureaucrats\n";

		delete person2;
	}
	{
		std::cout << "\n--> increment bureaucrat grades invalid\n";
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
	std::cout << COLOR_YELLOW << "\n===(DECREMENT GRADE TESTS)===\n\n" << COLOR_DEFAULT;
	
	{
		std::cout << "\n--> create valid bureaucrats\n";
		
		Bureaucrat	person1("Otto", 47);
		std::cout << person1 << std::endl;
		Bureaucrat	*person2 = new Bureaucrat("Ralf", 29);
		std::cout << person2 << std::endl;

		std::cout << "\n--> decrement bureaucrat grades valid\n";
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;

		person2->decrementGrade();
		std::cout << person2 << std::endl;
		person2->decrementGrade();
		std::cout << person2 << std::endl;
		
		std::cout << "\n--> deleting valid bureaucrats\n";

		delete person2;
	}
	{
		std::cout << "\n--> decrement bureaucrat grades invalid\n";
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
