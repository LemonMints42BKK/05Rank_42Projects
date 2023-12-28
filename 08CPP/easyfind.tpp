/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:05 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/26 23:49:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, int>
int easyfind(T &container, int n)
{
	T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return *it;
}