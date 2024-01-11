/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/11 12:39:10 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
#include <cstddef>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <typeinfo>


template <typename T>
class	PmergeMe{
	private:
		T _data;
		size_t _threshold;
		size_t _timeBegin;
		size_t _timeEnd;
		PmergeMe();
	public:
		PmergeMe(std::vector<std::string> arg);
		~PmergeMe();
		
		PmergeMe &operator=(PmergeMe const &rhs);
		
		void	putTimeBegin(size_t time);
		void	putTimeEnd(size_t time);
		T		getData() const;
		size_t	getTime () const;
		
		void	mergeInsertSort(T _data);
		void	printSort();

		class InvalidArgument : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("Error");
				}
		};
};
/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/

template <typename T>
PmergeMe<T>::PmergeMe(std::vector<std::string> arg): _threshold(50), _timeBegin(0), _timeEnd(0){
	for (size_t i = 0; i < arg.size(); i++){
		std::stringstream ss(arg[i]);
		size_t tmp;
		ss >> tmp;
		this->_data.push_back(tmp);
	}
}

template <typename T>
PmergeMe<T>::~PmergeMe(){
}

/************************************************
 *               Operator function              *
 ************************************************/

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe<T> const &rhs){
	if (this != &rhs){
		if (this->getData().size() != 0)
			this->_data.clear();
		for (size_t i = 0; i < rhs.getData().size(); i++){
			this->_data.push_back(rhs.getData().at(i));
		}
	}
	return (*this);
}

template <typename T>
std::ostream & operator<<( std::ostream & str, PmergeMe<T> const & rhs){
	str << rhs.getData().size() << " elements  with std::[ ";
	str << typeid(T).name() << " ] : ";
	str << rhs.getTime();
	str << " us" << std::endl;
	return (str);
}
/************************************************
 *              getter & setter                 *
 ************************************************/
template <typename T>
T PmergeMe<T>::getData() const{
	return (this->_data);
}

template <typename T>
void PmergeMe<T>::putTimeBegin(size_t time){
	this->_timeBegin = time;
}

template <typename T>
void PmergeMe<T>::putTimeEnd(size_t time){
	this->_timeEnd = time;
}

template <typename T>
size_t PmergeMe<T>::getTime() const{
	return (this->_timeEnd - this->_timeBegin);
}

/************************************************
 *               Member function                *
 ************************************************/

template <typename T>
void	PmergeMe<T>::mergeInsertSort(T sequence){
	(void)sequence;
	clock_t start_time = clock();
	putTimeBegin(start_time);
	//sleep(1);
	clock_t end_time = clock();
	putTimeEnd(end_time);
}

template <typename T>
void	PmergeMe<T>::printSort(){
	for(size_t i = 0; i < 5; i++){
		if (i == 4 && this->getData().size() > 5)
			std::cout << "[...]";
		else
			std::cout << this->getData().at(i) << " ";
	}
	std::cout << std::endl;
}