/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:34:55 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/23 22:30:58 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ATypeConverter.hpp"

// class TypeConverter;
class ScalarConverter: public ATypeConverter
{
	public:
		/* Constructors & Destructors */
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);
		/* Main Member Functions */
		static void convert(std::string literal);
		/* Exceptions */
};
