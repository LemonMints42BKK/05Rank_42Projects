/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:24 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:43:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class C : public Base
{
	private:
		std::string _type;
	public:
		C(void);
		C(C const &other);
		~C(void);
		C &operator=(C const &other);

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