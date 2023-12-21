/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:22 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/21 13:16:48 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		/* Constructors & Destructors */
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		/* Basic Operators */
		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &copy);

		/* Getters & Setters */
		void				putTarget(std::string const & target);
		std::string const &	getTarget(void) const;
		
		/* Main Member Functions */
		void				beExecuted(Bureaucrat const &executor) const;
};

std::ostream &				operator<<(std::ostream &str, RobotomyRequestForm const &form);