/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:44 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/10 14:08:20 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// template<typename T>
PmergeMe::PmergeMe(std::vector<std::string> arg) : _arg(arg){
	for(std::vector<std::string>::iterator it = this->_arg.begin(); it != this->_arg.end(); ++it){
		std::stringstream ss(*it);
		unsigned int var;
		if (ss >> var)
			this->_data.push_back(var);
		else
			throw std::invalid_argument("Invalid argument");
	}
}

// template<typename T>
PmergeMe::~PmergeMe(){
	std::cout << "Destructor" << std::endl;
}