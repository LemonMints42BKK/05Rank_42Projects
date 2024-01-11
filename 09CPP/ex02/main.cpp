/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:32 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/11 12:22:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Usage: ./pmergeMe <data>" << std::endl;
		return (EXIT_FAILURE);
	}
	try{
		std::vector<std::string> arg;
		for (int i = 1; i < argc; i++){
			for(int j = 0; argv[i][j]; j++){
				if (!isdigit(argv[i][j])){
					throw std::invalid_argument("Error");
				}	
			}
			arg.push_back(argv[i]);
		}
		PmergeMe<std::vector<size_t> > vec(arg);
		PmergeMe<std::deque<size_t> > deq(arg);
		std::cout << "Before: ";
		vec.printSort();
		
		vec.mergeInsertSort(vec.getData());
		deq.mergeInsertSort(deq.getData());
		
		std::cout << "After: ";
		vec.printSort();
		
		std::cout << "Time to process a range of "<< vec ;
		std::cout << "Time to process a range of "<< deq ;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}