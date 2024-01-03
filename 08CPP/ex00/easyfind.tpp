/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:24:05 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/03 13:44:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int const & Easy<T>::easyfind(T &container, int n)
{
	typename T::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw OutOfRangeException();
    return *it;
}