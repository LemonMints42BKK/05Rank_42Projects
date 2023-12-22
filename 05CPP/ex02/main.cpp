/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:33:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 08:29:32 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	/* Create the 3 forms and some Bureaucrats */
	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Rick Sanchez");
	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 46);
	Bureaucrat steve("Steve", 3);
	
	/* Try to execute forms without being signed */
	{
		try
		{
			std::cout << GREEN << steve << RESET <<std::endl;
			
			steve.executeForm(shrubbery);
			std::cout << RED << shrubbery << RESET << std::endl;
			
			steve.executeForm(robotomy);
			std::cout << RED << robotomy << RESET << std::endl;
			
			pardon.beSigned(steve);
			steve.executeForm(pardon);
			std::cout << BLUE << pardon << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute without enough grade */
	{
		try
		{
			ShrubberyCreationForm jonShrubbery = shrubbery;
			RobotomyRequestForm jonRobot = robotomy;
			jonShrubbery.putTarget("Jon");
			jonRobot.putTarget("Duke");
			std::cout << GREEN << jon << RESET <<std::endl;
			
			jonShrubbery.beSigned(jon);
			jon.executeForm(jonShrubbery);
			std::cout << BLUE << jonShrubbery << RESET << std::endl;
			
			jonRobot.beSigned(jon);
			jon.executeForm(jonRobot);
			std::cout << BLUE << jonRobot << RESET << std::endl;			
			
			pardon.beSigned(jon);
			jon.executeForm(pardon);
			std::cout << BLUE << pardon << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
		try
		{
			ShrubberyCreationForm mikeShrubbery = shrubbery;
			mikeShrubbery.putTarget("Mike");
			std::cout << std::endl;
			std::cout << GREEN << mike << RESET <<std::endl;
			
			mikeShrubbery.beSigned(mike);
			mike.executeForm(mikeShrubbery);
			std::cout << BLUE << mikeShrubbery << RESET << std::endl;
			
			robotomy.beSigned(mike);
			mike.executeForm(robotomy);
			std::cout << BLUE << robotomy << RESET << std::endl;			
			
			pardon.beSigned(mike);
			mike.executeForm(pardon);
			std::cout << BLUE << pardon << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them */
	{
		try
		{
			ShrubberyCreationForm steveShrubbery = shrubbery;
			RobotomyRequestForm steveRobot = robotomy;
			steveShrubbery.putTarget("Steve");
			steveRobot.putTarget("Bob");
			std::cout << GREEN << steve << RESET <<std::endl;
			
			steveShrubbery.beSigned(steve);
			steve.executeForm(steveShrubbery);
			std::cout << BLUE << steveShrubbery << RESET << std::endl;
			
			robotomy.beSigned(steve);
			steve.executeForm(robotomy);
			std::cout << BLUE << robotomy << RESET << std::endl;
			
			pardon.beSigned(steve);
			steve.executeForm(pardon);
			std::cout << BLUE << pardon << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n --------------------- \n\n";
	return (0);
}
