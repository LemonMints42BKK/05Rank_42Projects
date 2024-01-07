/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 17:37:53 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

int main(void){
	/*Test MyVactor class used as a container of integers*/
	try
	{
		std::vector<int> v;
		v.push_back(42);
		v.push_back(77);
		v.push_back(16);
		v.push_back(2);
		v.push_back(100);

		std::cout <<  "size is:"<<v.size() << std::endl;
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v.at(i) << std::endl;
		std::cout << "---------------------" << std::endl;
						
		std::cout << "Find 42 in vector: "<< Easy<std::vector<int> >::easyfind(v, 42) << std::endl;
		std::cout << "Find 10 in vector: "<< Easy<std::vector<int> >::easyfind(v, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/*test  with list container*/
		try
	{
		std::list<int> l;
		l.push_back(42);
		l.push_back(77);
		l.push_back(16);
		l.push_back(2);
		l.push_back(100);
		
		std::cout << "---------------------" << std::endl;
						
		std::cout << "Find 42 in list: "<< Easy<std::list<int> >::easyfind(l, 42) << std::endl;
		std::cout << "Find 10 in list: "<< Easy<std::list<int> >::easyfind(l, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	/*test  with deque container*/
	try
	{
		std::deque<int> d;
		d.push_back(42);
		d.push_back(77);
		d.push_back(16);
		d.push_back(2);
		d.push_back(100);
		
		std::cout << "---------------------" << std::endl;
		
		std::cout << "Find 100 in deque: "<< Easy<std::deque<int> >::easyfind(d, 100) << std::endl;
		std::cout << "Find 10 in degue: "<< Easy<std::deque<int> >::easyfind(d, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	/*test  with array container*/
	try
	{
		std::array<int, 5> a = {42, 77, 16, 2, 100};
		
		std::cout << "---------------------" << std::endl;
		
		std::cout << "Find 100 in array: "<< Easy<std::array<int, 5> >::easyfind(a, 100) << std::endl;
		std::cout << "Find 10 in array: "<< Easy<std::array<int, 5> >::easyfind(a, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/*test  with forward_list container*/
	try
	{
		std::forward_list<int> f;
		f.push_front(42);
		f.push_front(77);
		f.push_front(16);
		f.push_front(2);
		f.push_front(100);
		
		std::cout << "---------------------" << std::endl;
		
		std::cout << "Find 100 in forward_list: "<< Easy<std::forward_list<int> >::easyfind(f, 100) << std::endl;
		std::cout << "Find 10 in forward_list: "<< Easy<std::forward_list<int> >::easyfind(f, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}