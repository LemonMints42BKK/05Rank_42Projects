/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:58 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/21 11:09:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors & Destructors */
PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5), _target("default") {
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(std::string const & target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm::AForm(src), _target(src.getTarget()) {
	return ;
}
PresidentialPardonForm::~PresidentialPardonForm(void){
	return ;
}
/* Basic Operators */
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & copy){
	AForm::operator=(copy);
	this->putTarget(copy.getTarget());
	return (*this);
}
/* Getters & Setters */
void				PresidentialPardonForm::putTarget(std::string const & target){
	this->_target = target;
	return ;
}
std::string const &	PresidentialPardonForm::getTarget(void) const{
	return (this->_target);
}
/* Main Member Functions */
void				PresidentialPardonForm::beExecuted(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else 
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ;

}

std::ostream & operator<<(std::ostream & str, PresidentialPardonForm const & form){
	str << "Form's name: " << form.getName() << std::endl;
	str << "Signed: " << form.getIsSigned() << std::endl;
	str << "Sign Grade: " << form.getSignGrade() << std::endl;
	str << "Execute Grade: " << form.getExecGrade() << std::endl;
	str << "Form's target: " << form.getTarget() << std::endl;
	return (str);	
}