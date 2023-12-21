/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:35:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/20 20:49:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors & Destructors */
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name), _grade(grade){
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src.getName()), _grade(src.getGrade()) {
	return ;
}

Bureaucrat::~Bureaucrat(void){
	return ;
}

/* Basic Operators */
Bureaucrat const &	Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs)
	{	
		this->putGrade(rhs.getGrade());
	}
	return (*this);
}
/* Getters & Setters */
void				Bureaucrat::putGrade(int grade){
	this->_grade = grade;
	return ;	
}

std::string const &	Bureaucrat::getName(void) const{
	return (this->_name);
}

int	const &			Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

/* Main Member Functions */
void 				Bureaucrat::incGrade(void){
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->putGrade(this->getGrade() - 1);
	return ;
}

void 				Bureaucrat::decGrade(void){
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->putGrade(this->getGrade() + 1);
	return ;
}

void				Bureaucrat::signAForm(AForm &form){
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

void				Bureaucrat::executeAForm(AForm const &form) const{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << "Bureaucrat name's "<< bureaucrat.getName() << ", grade is " << bureaucrat.getGrade()<< ".");
}