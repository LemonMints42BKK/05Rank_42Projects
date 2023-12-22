/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:33:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 12:29:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int main(void)
// {

// 	return (0);
// }
std::string	megaphone(std::string str);

int main(int argc, char **argv)
{
    if (argc == 3){
        Intern intern;
        std::string lv = megaphone(argv[1]);
		std::string target = argv[2];
        if (lv == "PRESIDENTIALPARDON" || lv == "ROBOTOMYREQUEST" || lv == "SHRUBBERYCREATION"){
			Bureaucrat steve("Steve", 3);
			AForm * form = intern.makeForm(lv, target);
			try
			{
				std::cout << GREEN << steve << RESET <<std::endl;
				form->beSigned(steve);
				steve.executeForm(*form);
				std::cout << BLUE << *form << RESET << std::endl;
				delete form;
			}
			catch (std::exception &e)
			{	
				std::cout << e.what() << std::endl;
			}
        } else  {
            std::cout << YELLOW <<"[ Error! Form name is incorrect.]" << RESET << std::endl;
        }
    } else {
        std::cout << "Usage: ./ex03 [formName] [target]" << std::endl;
    }
    return 0;
}
std::string	megaphone(std::string str){
	int i = 0;
	while (str[i])
	{
		str[i] = (char)std::toupper(str[i]);
		i++;
	}
	return (str);
}