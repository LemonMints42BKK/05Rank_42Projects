/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:33:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 22:33:04 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string	mega(std::string str){
	int i = 0;
	while (str[i])
	{
		str[i] = (char)std::toupper(str[i]);
		i++;
	}
	return (str);
}

int main(void)
{
    Intern  someRandomIntern;
	AForm * form[4] = {someRandomIntern.makeForm(mega("ShrubberyCreation"), "Goodday"), someRandomIntern.makeForm(mega("RobotomyRequest"), "Bob") \
	, someRandomIntern.makeForm(mega("PresidentialPardon"), "Badboy"), someRandomIntern.makeForm(mega("helloWorld"), "Home")};
	
	try
	{
		int i = 0;
		Bureaucrat steve("Steve", 3);
		std::cout << GREEN << steve << RESET <<std::endl;
		while(form[i])
		{
			std::cout << BLUE << *form[i] << RESET << std::endl;
			form[i]->beSigned(steve);
			steve.executeForm(*form[i]);
			delete form[i];
			i++;
		}
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}
    return 0;
}


