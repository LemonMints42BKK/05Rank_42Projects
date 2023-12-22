/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 20:46:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Bureaucrat;
class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);
		/* Basic Operators */
		PresidentialPardonForm & operator=(PresidentialPardonForm const & copy);
		/* Getters & Setters */
		void				putTarget(std::string const & target);
		std::string const &	getTarget(void) const;
		/* Main Member Functions */
		void				beExecuted(Bureaucrat const &executor) const;
};

std::ostream & operator<<(std::ostream & str, PresidentialPardonForm const & form);