/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:05 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/09 21:23:11 by pnopjira         ###   ########.fr       */
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
			std::cout << " <<<<<<<< >>>>>>>> " << std::endl;
			std::unordered_multimap<std::string, float> *df = btc.getDF();
			for (std::unordered_multimap<std::string, float>::iterator it = df->begin(); it != df->end(); it++)
				std::cout << it->first << " " << it->second << std::endl;
				
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}