/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:28:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 19:37:22 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PREIDENTIALPARDONFORM_HPP
# define PREIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "colors.h"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm const & operator=(PresidentialPardonForm const & input);
		~PresidentialPardonForm(void);

		void	validExecution(Bureaucrat const & executor) const;
		std::string const & getFormType(void) const;

	protected:

	private:

		PresidentialPardonForm(PresidentialPardonForm const & input);
		static int const	_GRADE_TO_SIGN = 25;
		static int const	_GRADE_TO_EXCE = 5;
		std::string const	_FormType;
};

//std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & input);
//std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const * input);

#endif