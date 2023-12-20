/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:14 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 13:37:46 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors & Destructors */
Form::Form(void): _name("Default"), _isSigned(false), _signGrade(50), _execGrade(100) {
	return ;
}
Form::Form(std::string const &name, int const &signGrade, int const &execGrade):_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (getSignGrade() < 1 || getExecGrade() < 1)
	{	std::cout << "Form's ";
		throw Form::GradeTooHighException();}
	else if (getSignGrade() > 150 || getExecGrade() > 150)
	{	std::cout << "Form's ";
		throw Form::GradeTooLowException();}
	return ;
}
Form::Form(Form const &copy): _name(copy.getName()), _isSigned(copy.getIsSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
	return ;
}
Form::~Form(void){
	return ;
}

/* Basic Operators */
Form const 	&Form::operator=(Form const &copy){
	if (this != &copy)
	{
		this->putIsSigned(copy.getIsSigned());
	}
	return (*this);
}

/* Getters & Setters */
void				Form::putIsSigned(bool isSigned){
	this->_isSigned = isSigned;
	return ;
}
std::string const &	Form::getName(void) const{
	return (this->_name);
}
bool const &		Form::getIsSigned(void) const{
	return (this->_isSigned);
}
int const &			Form::getSignGrade(void) const{
	return (this->_signGrade);
}
int const &			Form::getExecGrade(void) const{
	return (this->_execGrade);
}

/* Main Member Functions */
void				Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > getSignGrade())
		throw(Form::GradeTooLowException());
	else
		putIsSigned(true);
	return ;
}

std::ostream	&operator<<(std::ostream &str, Form const &form){
	str << "Form " << form.getName() << " could signed";
	str << " with require grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return (str);
}