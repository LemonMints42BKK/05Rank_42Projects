/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AtypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:16:36 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/23 20:19:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATypeConverter.hpp"
/* Constructors & Destructors */
ATypeConverter::ATypeConverter(void): _var(0){
	return ;
}
ATypeConverter::ATypeConverter(double const & var): _var(var){
	return ;
}
ATypeConverter::ATypeConverter(ATypeConverter const & src){
	*this = src;
	return ;	
}
ATypeConverter::~ATypeConverter(void){
	return ;
}
/* Basic Operators */
ATypeConverter & ATypeConverter::operator=(ATypeConverter const & rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
ATypeConverter::operator double(){
	return (this->getVar());	
}
ATypeConverter::operator float(){
	return (static_cast<float>(this->getVar()));
}
ATypeConverter::operator int(){
	return (static_cast<int>(this->getVar()));
}
/* Getters & Setters */
void				ATypeConverter::putVar(double const & var){
	this->_var = var;
}
double const &		ATypeConverter::getVar(void){
	return (this->_var);
}
/* Main Member Functions */

/* Exceptions */
