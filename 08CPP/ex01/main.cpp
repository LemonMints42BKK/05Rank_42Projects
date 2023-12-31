/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 22:21:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <algorithm>
#include <ctime>

int generateRandomNumber() {
    return std::rand();
}

int main() {
	/*a maximum of integers is 0*/
	try {
		Span a(0);
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	/*Any attempt to add a new element if there are already N elements stored*/
	try {
		Span a(3);
		for (int i = 0; i < 4; i++){
			int tmp = rand() % 100;
			a.addNumber(tmp);
		}
		std::cout << "a : " << a << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	/*operator of equal*/
	try {
		Span a(4);
		Span b(8);
		for (unsigned int i = 0; i < a.getN(); i++){
			int tmp = rand() % 100;
			a.addNumber(tmp);
		}
		for (unsigned int i = 0; i < b.getN(); i++){
			int tmp = rand() % 100;
			b.addNumber(tmp);
		}
		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
		a = b;
		std::cout << "b = a, b : " << b << std::endl;
		// b = a;
		// std::cout << "a = b, a : " << a << std::endl;	
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	/*addNumber*/
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
   std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	/*with minimum of 10,000 numbers*/
	try {
        std::vector<int>    l( 25000 );
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        std::generate( l.begin(), l.end(), generateRandomNumber);

        Span span(l.size());

        span.addNumber( l.begin(), l.end() );
		//Span at begin and end numbers
		std::cout << "a[0] : " << span.getVec()->at(0) << std::endl;
		std::cout << "a[19999] : " << span.getVec()->at(19999) << std::endl;

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }

return 0;
}