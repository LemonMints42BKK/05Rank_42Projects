/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:32 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 17:17:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <positive integer>" << std::endl;
        return EXIT_FAILURE;
    }
    try {
		std::vector<std::string> arg;
		for (int i = 1; i < argc; i++){
			for(int j = 0; argv[i][j]; j++){
				if (!isdigit(argv[i][j])){
					throw std::invalid_argument("Error");
				}	
			}
			arg.push_back(argv[i]);
		}
		
		PmergeMe<std::vector<int> > vec(arg);

        std::cout << "Before:\t";
        vec.print_data();

        vec.sort();

		PmergeMe<std::deque<int> > dq(arg);
        dq.sort();

        std::cout << "After:\t";
        dq.print_data();

        if (vec.isSorted())
			vec.benchmark();
		else
			throw PmergeMe<std::vector<int> >::unSortedException();
        
		if (dq.isSorted())
			dq.benchmark();
		else
			throw PmergeMe<std::deque<int> >::unSortedException();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}