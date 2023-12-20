/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:33:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 13:40:13 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	/*Throw Bureaucrat grade to exception*/
	{
		try
		{
			Form form2("A50", 50, 100);
			std::cout << form2 << std::endl;
			Bureaucrat jon("Jon", 0);
			std::cout << jon << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			Form form2("A50", 50, 100);
			std::cout << form2 << std::endl;
			Bureaucrat mike("Mike", 151);
			std::cout << mike << std::endl;/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
	std::cout << "\n --------------------- \n\n";
	/* throw Form to exception  */
	{
		try
		{
			Form form0("A0", 0, 50);
			std::cout << form0 << std::endl;
			Bureaucrat meena("Meena", 49);
			std::cout << meena << std::endl;
			meena.signForm(form0);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form form1("A151", 151, 50);
			std::cout << form1 << std::endl;
			Bureaucrat meena("Meena", 49);
			std::cout << meena << std::endl;
			meena.signForm(form1);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n --------------------- \n\n";

	/* Create form and sign it without exceptions */
	{
		try
		{
			Form form2("A50", 50, 100);
			std::cout << form2 << std::endl;
			Bureaucrat meena("Meena", 49);
			std::cout << meena << std::endl;
			meena.signForm(form2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n --------------------- \n\n";

	/* Create form and try to sign it but the grade is not enough */
	{
		try
		{
			Form form2("C_303", 20, 45);
			Bureaucrat jon("Jon", 35);
			std::cout << form2 << std::endl;
			std::cout << jon << std::endl;
			jon.signForm(form2);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n --------------------- \n\n";
	return (0);
}
