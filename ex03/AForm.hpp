/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:36:59 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 19:39:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "colors.h"

class Bureaucrat;

class AForm
{

	public:

		AForm(std::string const & name, int gradeToSign, int gradeToExec);
		AForm(AForm const & input);
		AForm(AForm const * input);
		AForm const & operator=(AForm const & input);
		virtual ~AForm(void);

		void			execute(Bureaucrat const & executor) const;
		void			execute(Bureaucrat const * executor) const;
		void	executeFromBureaucrat(Bureaucrat const & executor) const;
		virtual void	validExecution(Bureaucrat const & executor) const = 0;
		virtual 		std::string const & getFormType(void) const = 0;
		
		std::string const &	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;

		void				beSigned(Bureaucrat const & input);
		void				beSigned(Bureaucrat const * input);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("AForm::GradeTooHighException");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("AForm::GradeTooLowException");
				}
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("AForm::FormAlreadySignedException");
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
		bool				_isSigned;
		int const			_GradeToSign;
		int const			_GradeToExec;

		static int const	_MAXGRADE = 1;
		static int const	_MINGRADE = 150;
};

std::ostream & operator<<(std::ostream & o, AForm const & input);
std::ostream & operator<<(std::ostream & o, AForm const * input);

#endif