/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:19 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 13:55:52 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;
class AForm{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		/* Constructors & Destructors */
		AForm(void);
		AForm(std::string const &name, int const &signGrade, int const &execGrade);
		AForm(AForm const &copy);
		virtual ~AForm(void);
		/* Basic Operators */
		AForm const	&operator=(AForm const &copy);
		/* Getters & Setters */
		void				putIsSigned(bool isSigned);
		std::string const &	getName(void) const;
		bool const &		getIsSigned(void) const;
		int const &			getSignGrade(void) const;
		int const &			getExecGrade(void) const;
		/* Main Member Functions */
		void				beSigned(Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		beExecuted(Bureaucrat const &executor) const = 0;
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
		class NotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){
					return ("form is not signed.");
				}
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);
