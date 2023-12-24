/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:35:43 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 21:33:09 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		/* Constructors & Destructors */
		Bureaucrat(void);
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		/* Basic Operators */
		Bureaucrat const &	operator=(Bureaucrat const & rhs);
		/* Getters & Setters */
		void				putGrade(int grade);
		std::string const &	getName(void) const;
		int	const &			getGrade(void) const;
		/* Main Member Functions */
		void 				incGrade(void);
		void 				decGrade(void);
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);
		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("Bureaucrat's grade is too high.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("Bureaucrat's grade is too low.");
				}
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);