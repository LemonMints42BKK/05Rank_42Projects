/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:29:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 16:31:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstddef>

template<typename T>
void	iter(T const *array,int const & len, void (*f)(T const &))
{
	int *l = const_cast<int *>(&len);
	for (int i = 0; i < *l; i++){
		f(array[i]);
		if (i != *l - 1){
			std::cout<< ", ";
		} else
			std::cout << std:: endl;
		
	}
}

template<typename T>
void	ft_print(T const &a)
{
		std::cout << a; 
}
