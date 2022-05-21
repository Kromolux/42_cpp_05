/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:24:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:36 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "colors.h"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm(std::string const & target);

		RobotomyRequestForm const & operator=(RobotomyRequestForm const & input);
		~RobotomyRequestForm(void);

		void	validExecution(Bureaucrat const & executor) const;
		std::string const & getFormType(void) const;

	protected:

	private:

		RobotomyRequestForm(RobotomyRequestForm const & input);
		static int const	_GRADE_TO_SIGN = 72;
		static int const	_GRADE_TO_EXCE = 45;
		std::string const	_FormType;
};

//std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & input);
//std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const * input);

#endif