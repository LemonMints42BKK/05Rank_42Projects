/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:17:16 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/04 10:26:43 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container> {
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(MutantStack const &other){*this = other;}
		MutantStack &operator=(MutantStack const &other){
			if (this != &other)
				std::stack<T, container>::operator=(other);
			return *this;}

		typedef typename std::stack<T, container>::container_type::iterator iterator;
		iterator begin(){return std::stack<T, container>::c.begin();}
		iterator end(){return std::stack<T, container>::c.end();}
};