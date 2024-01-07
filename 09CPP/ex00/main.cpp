/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:05 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/05 13:50:47 by pnopjira         ###   ########.fr       */
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
		// try {
			std::cout << " BitcoinExchange " << std::endl;
			BitcoinExchange btc;
			btc.execExchange(argv[1]);
			
		std::map<std::string, double> db = *(btc.getDB());
		for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); ++it) {
			std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		}
			
		// } catch (std::exception &e)
		// 	std::cout << e.what() << std::endl;
	}
	return (0);
}