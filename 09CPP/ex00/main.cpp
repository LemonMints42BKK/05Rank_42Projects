/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:05 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/10 20:29:40 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	} else {
		try {
			std::cout << " <<<<<<<< BitcoinExchange >>>>>>>> " << std::endl;
			BitcoinExchange btc;
			btc.execExchange(argv[1]);				
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}