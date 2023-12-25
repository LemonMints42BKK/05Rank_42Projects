/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:44 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:43:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class B : public Base
{
	private:
		std::string _type;
	public:
		B(void);
		B(B const &other);
		~B(void);
		B &operator=(B const &other);

		std::string getType() const;

	class BadCastException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Unrelates class: This class is not related to Base class.");
			}
	};
};