/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 17:17:07 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <exception>

// /* Type definitions */
// typedef std::vector<int> int_vector;

/* Class definition */
template<typename Container>
class PmergeMe {

private:
    Container   _data;
    double		_elapsedTime;
	int			_threshold;

	void		_tinsertionSort(Container & arr, int left, int right);
	void		_tmerge(Container & arr, int start, int mid, int end);
	void		_tmergeSort(Container & arr, int start, int end);
	PmergeMe(){}; // private default constructor
public:
	explicit PmergeMe(std::vector<std::string> arg);
    PmergeMe(const PmergeMe &other);
	~PmergeMe();
	
    PmergeMe &	operator=(const PmergeMe &other);
	
	void		putElapsedTime(double time);
	double		getElapsedTime() const;
	int			getThreshold() const;
	
    void		sort();
	bool		isSorted();
    void		print_data() const;
    void		benchmark() const;

	class unSortedException : public std::exception{
		public:
			virtual const char *what() const throw(){
				return ("Error");
			}
	};
};