/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:30:13 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 12:41:11 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors & Destructors */
Intern::Intern(void){
	return ;
}
Intern::Intern(Intern const &src){
	*this = src;
	return ;
}
Intern::~Intern(void){
	return ;
}

/* Basic Operators */
Intern &	Intern::operator=(Intern const &copy){
	(void)copy;
	return (*this);
}

/* Main Member Functions */
AForm *		Intern::makeForm(std::string const &nameForm, std::string const &target){
	AForm* form[] = { new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	std::string formName[] = {"PRESIDENTIALPARDON", "ROBOTOMYREQUEST", "SHRUBBERYCREATION"};

	int ch = 0;
    for (int i = 0; i < 3; i++){
        if (nameForm == formName[i])
            ch = i;
		else
			delete form[i];
    }
	if (ch != 0)
		std::cout << YELLOW << "Intern creates " << formName[ch] << RESET << std::endl;
	return (form[ch]);
}