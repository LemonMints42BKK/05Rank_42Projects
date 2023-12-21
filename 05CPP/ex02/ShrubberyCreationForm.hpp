/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/21 12:25:58 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define TREE "               ,@@@@@@@,	\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.	\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o	\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'	\n\
   %&&%/ %&%%&&@@\\ \\V /@@' `88\\8 `/88'	\n\
   `&%\\ ` /%&'    |.|        \\ '|8'		\n\
       |o|        | |         | |		\n\
       |.|        | |         | |		\n\
42BKK\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__	\n"

class Bureaucrat;
class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	public:
		/* Constructors & Destructors */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);

		/* Basic Operators */
		ShrubberyCreationForm const	&	operator=(ShrubberyCreationForm const &copy);
		/* Getters & Setters */
		void				putTarget(std::string const & target);
		std::string const &	getTarget(void) const;
		/* Main Member Functions */
		void							beExecuted(Bureaucrat const &bureaucrat) const;
};
std::ostream &							operator<<(std::ostream &str, ShrubberyCreationForm const &form);