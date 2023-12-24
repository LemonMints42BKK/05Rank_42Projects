/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:44:44 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/24 08:43:23 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isDecimalNotation(const std::string & input){
	bool hasDigit = false;
	bool hasDecimalPoint = false;
	bool hasSuffix = false;
	
	if (input.empty())
		return (false);
	for (std::string::size_type i = 0; i < input.length() ; i++){
		if (isdigit(input.at(i))){
			hasDigit = true;
		} else if (input.at(i) == '.'){
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		} else if (input.at(i) == 'F'|| input.at(i) == 'f'){
			if (hasSuffix)
				return (false);
			hasSuffix = true;
		} else if (i == 0 && (input.at(0) == '-' || input.at(0) == '+')){
			
		} else
			return (false);
	}
	return (hasDigit);
}

bool	isChar(const std::string & input){
	bool hasChar = false;
	
	if (input.length() == 1 && (input.at(0) >= 32 && input.at(0) <= 126))
		hasChar = true;
	return (hasChar);
}

bool	isPseudoLiterals(const std::string & input){
	bool hasPseudo = false;
	if (input == "nan" || input == "-inff" || input == "+inff" || input == "inff" \
	|| input == "-inf" || input == "+inf" || input == "inf" )
		hasPseudo = true;
	return (hasPseudo);
}

int main(int argc, char** argv){
	if (argc == 2){
		std::string input = argv[1];
		if (isDecimalNotation(input) || isChar(input) || isPseudoLiterals(input))
			ScalarConverter::convert(input);
		else
			return (perror("non displayable characters shouldn’t be used, only the decimal notation."), EXIT_FAILURE);
	}
	else
		std::cout << ">>> invalid argument <<<" << std::endl;
	return (EXIT_SUCCESS);
}