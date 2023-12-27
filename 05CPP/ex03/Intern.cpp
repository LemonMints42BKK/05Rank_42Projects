/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:30:13 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/27 22:33:48 by pnopjira         ###   ########.fr       */
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
	std::string formName[] = {"PRESIDENTIALPARDON", "ROBOTOMYREQUEST", "SHRUBBERYCREATION"};
	int index = -1;
	AForm *form = NULL;
	for (int i = 0; i < 3; i++){
		if (nameForm == formName[i])
		{
			index = i;
			std::cout << YELLOW << "Intern creates " << formName[index] << RESET << std::endl;
			break;	
		}
	}
	switch (index)
	{
	case 0 :
		form = new PresidentialPardonForm(target);
		return (form);
	case 1 :
		form = new RobotomyRequestForm(target);
		return (form);
	case 2 :
		form = new ShrubberyCreationForm(target);
		return (form);
	default:
		std::cout << YELLOW <<"[ Error! Form's name is incorrect.]" << RESET << std::endl;
		break;
	}
	return (NULL);
}