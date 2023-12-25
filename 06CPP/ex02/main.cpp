/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:18 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 11:11:12 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

Base *generate(void){
	int random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p){
	try{
		A &a = dynamic_cast<A&>(*p);
		std::cout << RED << a.getType() << RESET << std::endl;
	} catch (std::exception &e){
		try{
			B &b = dynamic_cast<B&>(*p);
			std::cout << GREEN << b.getType() << RESET << std::endl;
		} catch (std::exception &e){
			try{
				C &c = dynamic_cast<C&>(*p);
				std::cout << BLUE << c.getType() << RESET << std::endl;
			} catch (std::exception &e){
				std::cout << e.what() << std::endl;
			}
		}
	}
}

void identify(Base &p){
	try{
		A &a = dynamic_cast<A&>(p);
		std::cout << RED << (a).getType() << RESET << std::endl;
	} catch (std::exception &e) {
		try{
			B &b = dynamic_cast<B&>(p);
			std::cout << GREEN << b.getType() << RESET << std::endl;
		} catch (std::exception &e){
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << BLUE << c.getType() << RESET << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
}

int main (void){
	for (int i = 0; i < 10; i++){
		Base *base = generate();
		
		std::cout << YELLOW << "identify by referance to pointer: " << RESET;
		identify(base);
		std::cout << std::endl;
		std::cout << "identify by pointer to referance: ";
		identify(*base);
		std::cout << "\n--------------------------------" << std::endl;
		delete base;
	}	
	return (0);
}