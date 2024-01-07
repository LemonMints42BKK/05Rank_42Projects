/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:16:04 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 22:29:56 by pnopjira         ###   ########.fr       */
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
	// /*std::stack does expose its iterators to subclasses through its protected interface */
	// std::stack<int>::iterator sit = s.begin(); std::stack<int>::iterator site = s.end();
	// while (sit != site) {
	// 	std::cout << *sit << std::endl;
	// 	++sit;
	
	std::cout << "---------------------" << std::endl;
	
	std::cout << ">>>>>List<<<<<" << std::endl;
	
	std::list<int> mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	
	std::cout << "print back: " << mlist.back() << std::endl;
	
	mlist.pop_back();
	
	std::cout << "print size: " << mlist.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itle = mlist.end();
	
	++itl;
	--itl;
	while (itl != itle) {
		std::cout << *itl << std::endl;
		++itl; 
	}
	
	return 0;
}