/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:36:59 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 11:21:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "colors.h"

class Bureaucrat;

class Form
{

	public:

		Form(std::string const & name, int gradeToSign, int gradeToExec);
		Form(Form const & input);
		Form const & operator=(Form const & input);
		~Form(void);

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
					return ("Form::GradeTooHighException");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form::GradeTooLowException");
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

std::ostream & operator<<(std::ostream & o, Form const & input);
std::ostream & operator<<(std::ostream & o, Form const * input);

#endif