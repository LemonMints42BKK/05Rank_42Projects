/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:34:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/24 11:49:19 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATypeConverter.hpp"
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <climits>
#include <cfloat>
#include <cmath>
/* Constructors & Destructors */
ScalarConverter::ScalarConverter(void){
	return ;
}
ScalarConverter::ScalarConverter(ScalarConverter const & src){
	*this = src;
	return ;	
}
ScalarConverter::~ScalarConverter(void){
	return ;
}
/* Main Member Functions */

double	pseudoLiterals(const std::string &	literal){
	if (literal == "nan")
		return (std::sqrt(-1.0));
	if (literal == "+inf"  || literal == "inf")
		return (std::numeric_limits<float>::infinity());
	if (literal == "+inff" || literal == "inff")
		return (std::numeric_limits<double>::infinity());
	if (literal == "-inf" )
		return (-std::numeric_limits<float>::infinity());
	if (literal == "-inff")
		return (-std::numeric_limits<double>::infinity());
	return (0);
}

double	typeChar(const std::string &	literal){
	if (literal.length() == 1 && (literal.at(0) >= 32 && literal.at(0) <= 126)){
		if (literal.at(0) >= 48 && literal.at(0) <= 57)
			return (false);
		else
			return (literal.at(0));
	}
	return (0);
}

double	decimalNotation(const std::string &	literal){
	std::istringstream iss(literal);
	double numDouble = 0.0;
			
	if (iss >> numDouble){
		char sign = '\0';
		if (iss.get(sign) && (sign == '+' || sign == '-')){
			if (sign == '-')
				numDouble *= -1;
		}
		char suffix = '\0';
		if (iss >> suffix && (std::tolower(suffix) == 'f')){
			numDouble = static_cast<float>(numDouble);	
		} else {
			iss.putback(suffix);
		}	
	} else {
		std::cerr << "Conversion failed for string: " << literal << std::endl;
	}
	return (numDouble);
}

void ScalarConverter::convert(std::string literal){
	double lit = 0.0;
	bool isChar = false;
	bool isDecimalPoint = false;
	
	if (pseudoLiterals(literal)){
		lit = pseudoLiterals(literal);
	} else if (typeChar(literal)){
		isChar = true;
		lit = typeChar(literal);
	} else if (decimalNotation(literal)){
		isDecimalPoint = true;
		lit = decimalNotation(literal);
	} else {
		std::istringstream str(literal);
		str >> lit;
	}
	ScalarConverter var;
	var.putVar(lit);
	char16_t	a	=	'\0';
	int			b	=	var;
	float		c	=	var;
	double		d	=	var;
	
	if (b >= 32 && b <= 126)
		a = static_cast<char16_t>(b);
	
	if (a == 0 && b == -2147483648)
		std::cout << "char: " << "impossible" << std::endl;
	else if (a == 0 && b == 0)
		std::cout << "char: " << "Non displayable" << std::endl;
	else{
		if (b != 0 && !isChar)
			a = '*';
		std::cout << "char: " << "'" << static_cast<char>(a) << "'" << std::endl;
	}
	
	if (b == -2147483648)
		std::cout << "char: " << "impossible" << std::endl;
	else
		std::cout << "int: " << b << std::endl;
		
	if ((d != 0 ) && isDecimalPoint){	
		std::cout << "float: " << c << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if ((d == 0) || !isDecimalPoint){
		std::cout << "float: " << c << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}

}
/* Exceptions */