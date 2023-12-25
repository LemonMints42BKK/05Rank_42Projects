/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:33:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 20:35:11 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <iomanip>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
};