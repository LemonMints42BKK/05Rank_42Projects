/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:29 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/10 22:53:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <map>
#include <unordered_map>

class BitcoinExchange {
	private:
		std::string						_database;
		std::string						_datafile;
		std::multimap<std::string, float>	_db;
		
		void _dataToMap(std::string data, char 	ch, std::multimap<std::string, float> *map);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string data);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(); 
					
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void							putDatafile(std::string argv);		
		std::string						getDatabase() const;
		std::string						getDatafile() const;
		std::multimap<std::string, float>	*getDB() const;
		
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
bool isValidValue(float *value, char ch);
std::string trim(const std::string& s);
float findClosestLowerDate(const std::multimap<std::string, float>& database, const std::string & inputDate);