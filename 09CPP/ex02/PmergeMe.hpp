/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 12:57:31 by pnopjira         ###   ########.fr       */
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

/* Type definitions */
typedef std::vector<int> int_vector;

/* Class definition */
template<typename Container>
class PmergeMe {

public:
    typedef typename Container::value_type      value_type;
    typedef typename Container::size_type       size_type;
    typedef std::pair <value_type, value_type>  type_pair;
    typedef std::vector <type_pair>             pair_vector;

private:
    Container   _data;
    value_type  _last;
    double		_elapsedTime;

    int_vector  generate_indexes(size_t n);
    pair_vector generate_pairs(Container &data);
    void        sort_pairs(pair_vector &pairs);
    int         binary_search(int target);
	PmergeMe(){}; // private default constructor
public:
	explicit PmergeMe(std::vector<std::string> arg);
    PmergeMe(const PmergeMe &other);
	~PmergeMe();
	
    PmergeMe &	operator=(const PmergeMe &other);
	
	void		putElapsedTime(double time);
	double		getElapsedTime() const;
	
    void		sort();
    void		print_data() const;
    void		benchmark() const;
};