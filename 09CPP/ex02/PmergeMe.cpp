/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:44 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/11 00:04:40 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(std::vector<std::string> arg){
	for (size_t i = 0; i < arg.size(); i++){
		std::stringstream ss(arg[i]);
		size_t tmp;
		ss >> tmp;
		this->_data.push_back(tmp);
	}
	// for (size_t i = 0; i < this->getData().size(); i++){
	// 	std::cout << this->getData().at(i) << " ";
	// }
	// std::cout << std::endl;
}

template <typename T>
PmergeMe<T>::~PmergeMe(){
}

template <typename T>
T PmergeMe<T>::getData() const{
	return (this->_data);
}
