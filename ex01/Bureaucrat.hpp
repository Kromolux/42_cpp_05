/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:30:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 11:22:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"
# include "colors.h"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & input);
		Bureaucrat const & operator=(Bureaucrat const & input);
		~Bureaucrat(void);

		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form & form) const;
		void				signForm(Form * form) const;
	
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat::GradeTooHighException");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat::GradeTooLowException");
				}
		};

	protected:

	private:
	
		std::string	const	_name;
		int					_grade;
		static int const	_MAXGRADE = 1;
		static int const	_MINGRADE = 150;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input);
std::ostream & operator<<(std::ostream & o, Bureaucrat const * input);

#endif