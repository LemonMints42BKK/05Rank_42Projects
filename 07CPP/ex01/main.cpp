/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:28:48 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 16:21:52 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int 		iTab[] = {0, 1, 2, 3, 4};
	::iter(iTab, 5, &ft_print);

	float 		fTab[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
	::iter(fTab, 5, &ft_print);
	
	double		dTab[] = {0.0, 1.1, 2.2, 3.3, 4.4};
	::iter(dTab, 5, &ft_print);
	
	char 		cTab[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(cTab, 5, &ft_print);

	std::string sTab[] = {"Hello", "World", "!"};
	::iter(sTab, 3, &ft_print);

    return 0;
}