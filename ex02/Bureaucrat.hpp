/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:30:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 18:32:23 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"
# include "colors.h"

class AForm;

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

		void				signForm(AForm & form) const;
		void				signForm(AForm * form) const;
	
		void				executeForm(AForm const & form) const;
		void				executeForm(AForm const * form) const;

		void				executeFromForm(AForm const & form) const;

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
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("AForm::FormNotSignedException");
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