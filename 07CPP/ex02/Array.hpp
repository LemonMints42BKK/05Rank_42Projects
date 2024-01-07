/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:29:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/28 08:30:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array {	
	public:
		Array(void) {}
		Array(unsigned int n): _arr(new T[n]), _n(n){
			for (unsigned int i = 0; i < n; i++)
				this->_arr[i] = 0;}
		Array(Array const &src): _arr(new T[src._n]),  _n(src._n){
			for (unsigned int i = 0; i < src._n; i++)
				this->_arr[i] = src._arr[i];}
		~Array(void) {delete [] this->_arr;}
		
		T *		getArr(void) const {return this->_arr;}
		const unsigned int & 	size(void) const;
		
		Array &	operator=(Array const &rhs);
		T & 	operator[](unsigned int const & i);
				
	private:
		T *				_arr;
		unsigned int	_n;
	
	class IndexOutOfLimit : public std::exception
	{
		public:
			virtual const char* what() const throw() {return ("Index number is out of limit");}
	};
};

#include "Array.tpp"