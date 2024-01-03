/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:55:16 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/03 21:42:37 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <vector>

class Span {
	private:
		unsigned int _n;
		std::vector<int> *_vec;
		
		Span();
	public:	
		
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &copy);
		
		unsigned int getN() const;
		std::vector<int> & getVec() const;
		
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
	
	class isFull: public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Already Full");
			}
	};
	class noSpan: public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("no span can be found");
			}
	};		
};

std::ostream & operator<<( std::ostream & str, Span const & rhs);