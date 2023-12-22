/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:30:10 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 12:14:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern
{	
	public:
		/* Constructors & Destructors */
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		/* Basic Operators */
		Intern &	operator=(Intern const &rhs);

		/* Main Member Functions */
		AForm *	makeForm(std::string const &nameForm, std::string const &target);
};