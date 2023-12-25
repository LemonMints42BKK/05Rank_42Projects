/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:55 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:43:19 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class A : public Base
{
	private:
		std::string _type;
	public:
		A(void);
		A(A const &other);
		~A(void);
		A &operator=(A const &other);

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