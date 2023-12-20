/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:19 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 13:07:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;
class Form{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		/* Constructors & Destructors */
		Form(void);
		Form(std::string const &name, int const &signGrade, int const &execGrade);
		Form(Form const &copy);
		~Form(void);
		/* Basic Operators */
		Form const	&operator=(Form const &copy);
		/* Getters & Setters */
		void				putIsSigned(bool isSigned);
		std::string const &	getName(void) const;
		bool const &		getIsSigned(void) const;
		int const &			getSignGrade(void) const;
		int const &			getExecGrade(void) const;
		/* Main Member Functions */
		void				beSigned(Bureaucrat &bureaucrat);
		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("grade is too high.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("grade is too low.");
				}
		};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);
