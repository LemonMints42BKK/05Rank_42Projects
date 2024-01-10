/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:32 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/10 13:51:07 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Usage: ./PmergeMe <data> " << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		std::vector<std::string> arg;
		for (int i = 1; i < argc; i++){
			for (int j = 0; argv[i][j]; j++){
				if (!isdigit(argv[i][j]))
					throw std::invalid_argument("Invalid argument");
			}
			arg.push_back(argv[i]);
		}
		
		PmergeMe pmm(arg);
		// PmergeMe<std::string, std::string> pmm(argv[1]);
		// std::cout << pmm.getResult() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}