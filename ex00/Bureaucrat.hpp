/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:30:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 21:52:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "colors.h"

class Bureaucrat
{

	public:

		Bureaucrat(std::string const & name, unsigned int & grade);
		Bureaucrat(Bureaucrat const & input);
		Bureaucrat const & operator=(Bureaucrat const & input);
		~Bureaucrat(void);

		std::string const &	getName(void) const;
		unsigned int	getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

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
		unsigned int		_grade;
		unsigned int const	_MaxGrade = 1;
		unsigned int const	_MinGrade = 150;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input);

#endif