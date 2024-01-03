/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:08 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/03 13:46:30 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template<typename T>
class Easy {
	public:
		static int const & easyfind (T &container, int n); 
	class OutOfRangeException : public std::exception
	{
		public:
			virtual const char *what() const throw() { return "Value not found in container";}
	};		
};

#include "easyfind.tpp"
