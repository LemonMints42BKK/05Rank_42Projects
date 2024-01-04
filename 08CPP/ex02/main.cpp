/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:16:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/04 11:01:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(){
	std::cout << ">>>>>Mutant Stack<<<<<" << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "print top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "print size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); 
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite) {
    	std::cout << *it << std::endl;
		++it; 
	}
	
	// std::stack<int> s(mstack);
	/*std::stack does expose its iterators to subclasses through its protected interface */
	// std::stack<int>::iterator sit = s.begin(); std::stack<int>::iterator site = s.end();
	// while (sit != site) {
	// 	std::cout << *sit << std::endl;
	// 	++sit;
	
	std::cout << "---------------------" << std::endl;
	
	// std::cout << ">>>>>List<<<<<" << std::endl;
	
	// std::list<int> mstack;
	
	// mstack.push_back(5);
	// mstack.push_back(17);
	
	// std::cout << "print back: " << mstack.back() << std::endl;
	
	// mstack.pop_back();
	
	// std::cout << "print size: " << mstack.size() << std::endl;
	
	// mstack.push_back(3);
	// mstack.push_back(5);
	// mstack.push_back(737);
	// mstack.push_back(0);
	
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	
	// ++it;
	// --it;
	// while (it != ite) {
	// 	std::cout << *it << std::endl;
	// 	++it; 
	// }
	
	// std::cout << std::endl;
	// std::list<int> s(mstack);
	// std::list<int>::iterator sit = s.begin(); std::list<int>::iterator site = s.end();
	// while (sit != site) {
	// 	std::cout << *sit << std::endl;
	// 	++sit; 
	// }
	return 0;
}