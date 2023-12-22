/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:26 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/21 11:33:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors & Destructors */
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("default"){
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target){
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm::AForm(src), _target(src.getTarget()){
	return ;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void){
	return ;
}

/* Basic Operators */
ShrubberyCreationForm const	&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy){
	AForm::operator=(copy);
	this->putTarget(copy.getTarget());
	return(*this);
}

/* Getters & Setters */
void				ShrubberyCreationForm::putTarget(std::string const & target){
	this->_target = target;
}
std::string const &	ShrubberyCreationForm::getTarget(void) const{
	return (this->_target);
}

/* Main Member Functions */
void				ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const{
	std::ofstream	outfile;
	outfile.open((this->getTarget() +  "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
	outfile << this->getTarget() << TREE;
	outfile.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;
	return ;
}

std::ostream &		operator<<(std::ostream &str, ShrubberyCreationForm const &form){
	str << "Form's name: " << form.getName() << std::endl;
	str << "Signed: " << form.getIsSigned() << std::endl;
	str << "Sign Grade: " << form.getSignGrade() << std::endl;
	str << "Execute Grade: " << form.getExecGrade() << std::endl;
	str << "Form's target: " << form.getTarget() << std::endl;
	return (str);
}