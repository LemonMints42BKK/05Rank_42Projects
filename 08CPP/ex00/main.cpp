/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/03 13:49:16 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

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
		v.pop_back();

		std::cout <<  "size is:"<<v.size() << std::endl;
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v.at(i) << std::endl;
		std::cout << "---------------------" << std::endl;
		
		std::sort(v.begin(), v.end());
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v.at(i) << std::endl;

		std::cout << "---------------------" << std::endl;
						
		std::cout << "Find 42 : "<< Easy<std::vector<int> >::easyfind(v, 42) << std::endl;
		std::cout << "Find 10: "<< Easy<std::vector<int> >::easyfind(v, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}