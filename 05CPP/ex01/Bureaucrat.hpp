/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:35:43 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/19 14:02:32 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;
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
		void				signForm(Form &form);
		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("Grade is too high");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("Grade is too low");
				}
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);