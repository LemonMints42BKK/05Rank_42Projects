/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/10 14:02:43 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

/* Type definitions */
typedef std::vector<int> int_vector;

// template<typename T>
class PmergeMe{
	private:
		std::vector<std::string>	_arg;
		std::vector<unsigned int>	_data;
		double				_timeBegin;
		double				_timeEnd;
		
		PmergeMe();	
	public:	
		PmergeMe(std::vector<std::string> arg);
		// PmergeMe<T>(PmergeMe const &other);
		~PmergeMe();

		// PmergeMe &operator=(PmergeMe const &other);

		// void			putTimeBegin();
		// void 			putTimeEnd();
		// std::string		getExpression() const;
		// container		getData() const;
		// container		getSequence() const;
		// double			getTimeBegin() const;
		// double			getTimeEnd() const;
		
		// void	mergeInsertSort(container<size_t>::iterator begin, container<size_t>::iterator end);		// this->_time = this->getTime()
};