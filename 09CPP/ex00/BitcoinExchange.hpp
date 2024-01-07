/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:29 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 20:43:25 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <map>

class BitcoinExchange {
	private:
		std::string						_database;
		std::string						_datafile;
		std::map<std::string, float>	*_db;
		std::map<std::string, float>	*_df;
		
		void _dataToMap(std::string data, char 	ch, std::map<std::string, float> *map);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string data);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(); 
					
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void							putDatafile(std::string argv);		
		std::string						getDatabase() const;
		std::string						getDatafile() const;
		std::map<std::string, float>	*getDB() const;
		std::map<std::string, float>	*getDF() const;
		
		void	execExchange(std::string argv);
		class FileNotFound : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: could not open file.");
				}
		};
};

bool isValidFile(std::string file);
bool isValidDate(std::string date);
bool isValidValue(float value);
std::string trim(const std::string& s);