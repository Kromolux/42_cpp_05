/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:07:24 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 17:49:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "colors.h"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm(std::string const & name);
		ShrubberyCreationForm(ShrubberyCreationForm const & input);
		ShrubberyCreationForm(ShrubberyCreationForm const * input);
		ShrubberyCreationForm const & operator=(ShrubberyCreationForm const & input);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm *	clone(void) const;
		void	validExecution(Bureaucrat const & executor) const;
		std::string const & getFormType(void) const;

		class CantAccessFileException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("ShrubberyCreationForm::CantAccessFileException");
				}
		};

	protected:

	private:

		static int const	_GRADE_TO_SIGN = 145;
		static int const	_GRADE_TO_EXCE = 137;
		std::string const _FormType;
};

//std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & input);
//std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const * input);

#endif