/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:34:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 07:58:45 by pnopjira         ###   ########.fr       */
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

bool	typeChar(const std::string &	literal, double &num, bool &isChar){
	if (literal.length() == 1 && (literal.at(0) >= 32 && literal.at(0) <= 126)){
		if (literal.at(0) >= 48 && literal.at(0) <= 57)
			return (false);
		else{
			num = static_cast<double>(literal.at(0));
			isChar = true;
			return (true);
		}
	}
	return (false);
}

bool read_double(std::string str, double *num)
{
    std::stringstream ss;

    ss << str;
    ss >> *num;
    return (!ss.fail());
}

bool	read_double_complete(std::string str, double &num, bool &isChar, bool &isDecimalNotation){
	if (typeChar(str, num, isChar))
		return (true);
	while (str.length() > 0)
    {
        if (read_double(str, &num)){
			// if (num == INFINITY || num == -INFINITY || num == std::sqrt(-1.0))
			// 	isDecimalNotation = true;
            return (true);
		}
        str.erase(str.length() - 1, 1);
		if (str.at(str.length() - 1) == '.')
			isDecimalNotation = true;
    }
	return (false);
}

void ScalarConverter::convert(std::string literal){
	double lit = 0.0;
	bool isChar = false;
	bool isDecimalNotation = false;
	char16_t	a = '\0';
	int			b = 0;
	float		c = 0;
	double		d = 0;

	if (read_double_complete(literal, lit, isChar, isDecimalNotation)){
		ScalarConverter var;
		var.putVar(lit);
		a =	'\0';
		b =	var;
		c =	var;
		d =	var;
	}
    else
        throw ScalarConverter::CanNotConvertException();
		
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
		
	if (isDecimalNotation || c == INFINITY || c == -INFINITY || c != c) {	 // from IEEE stand NaN values 
		std::cout << "float: " << c << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	} else {
		std::cout << "float: " << c << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
}