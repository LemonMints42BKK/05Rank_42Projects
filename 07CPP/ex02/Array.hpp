/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:29:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 20:45:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
class Array {
	private:
		Array<T>(void) {}
		Array<T>(unsigned int n) { T *this->_arr = new int(n); std::cout << *this->_arr << std::endl;}
		Arrey<T>(Array const &src);
		~Array<T>(void) {} 
	
	public:
		T *	_arr;
}


