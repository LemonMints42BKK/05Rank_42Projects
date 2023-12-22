/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/22 08:31:04 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors & Destructors */
RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("default"){
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target){
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm::AForm(src), _target(src.getTarget()){
	return ;
}
RobotomyRequestForm::~RobotomyRequestForm(void){
	return ;
}

/* Basic Operators */
RobotomyRequestForm const &	RobotomyRequestForm::operator=(RobotomyRequestForm const &copy){
	AForm::operator=(copy);
	this->putTarget(copy.getTarget());	
	return (*this);
}

/* Getters & Setters */
void				RobotomyRequestForm::putTarget(std::string const & target){
	this->_target = target;
}
std::string const &	RobotomyRequestForm::getTarget(void) const{
	return (this->_target);
}
		
/* Main Member Functions */
void				RobotomyRequestForm::beExecuted(Bureaucrat const &executor) const{
	int	success;
	/* Set Seed */
	srand((unsigned) time(NULL));
	success = rand() % 2;
	(void)executor;
	if (success)
		std::cout << this->_target << " has been robotomized successfully 50\% of the time. " << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
	return ;
}

std::ostream &				operator<<(std::ostream &str, RobotomyRequestForm const &form){
	str << "Form's name: " << form.getName() << std::endl;
	str << "Signed: " << form.getIsSigned() << std::endl;
	str << "Sign Grade: " << form.getSignGrade() << std::endl;
	str << "Execute Grade: " << form.getExecGrade() << std::endl;
	str << "Form's target: " << form.getTarget() << std::endl;
	return (str);
}
