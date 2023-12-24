/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AtypeConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:16:33 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/23 20:33:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ATypeConverter
{
	private:
		double	_var;
	public:
		/* Constructors & Destructors */
		ATypeConverter(void);
		ATypeConverter(double const & var);
		ATypeConverter(ATypeConverter const & src);
		virtual ~ATypeConverter(void);
		/* Basic Operators */
		ATypeConverter & operator=(ATypeConverter const & rhs);
		operator double();
		operator float();
		operator int();
		/* Getters & Setters */
		void				putVar(double const & var);
		double const &		getVar(void);
		/* Main Member Functions */
		/* Exceptions */
};