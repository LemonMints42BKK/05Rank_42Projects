/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:33:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/26 22:51:21 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename U>
Array<U> numbers(U const &n)
{
	Array<U> arr(n);
	return (arr);
}

template <typename U>
Array<U> time(Array<U> &arr)
{
	clock_t start, end;
	start = clock();
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = rand();
	end = clock();
	std::cout << "Time taken to assign " << arr.size() << " elements: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
}