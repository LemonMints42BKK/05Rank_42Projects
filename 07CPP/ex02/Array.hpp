/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:29:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/26 22:55:20 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>

template <typename T>
class Array {
	
	class IndexOutOfLimit : public std::exception
	{
		public:
			virtual const char* what() const throw() {return ("Index number is out of limit");}
	};
	
	public:
		Array<T>(void) {}
		Array<T>(unsigned int n): _arr(new T[n]), _n(n){
			for (unsigned int i = 0; i < n; i++)
				this->_arr[i] = 0;}
		Array<T>(Array const &src): _arr(new T[src._n]),  _n(src._n){
			for (unsigned int i = 0; i < src._n; i++)
				this->_arr[i] = src._arr[i];}
		Array & operator=(Array const &rhs){
			if (this != &rhs)
			{
				delete [] this->_arr;
				this->_n = rhs._n;
				this->_arr = new T[rhs._n];
				for (unsigned int i = 0; i < rhs._n; i++)
					this->_arr[i] = rhs._arr[i];
			} else{return *this;}
			return *this;
		}
		T & operator[](unsigned int const & i) const {if (i >= this->_n)throw IndexOutOfLimit(); return this->_arr[i];}
		T & size(void) const {return (static_cast<T>(this->_n));}
		~Array<T>(void) {delete [] this->_arr;}
	
	private:
		T *	_arr;
		unsigned int _n;
};

#include "Array.tpp"