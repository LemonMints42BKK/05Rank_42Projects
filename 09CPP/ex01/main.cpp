/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:25:27 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/09 23:33:54 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "inverted Polish mathematical expression Usage: ./RPN \"<expression>\" " << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}