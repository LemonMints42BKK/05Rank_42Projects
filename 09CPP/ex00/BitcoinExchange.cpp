/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:29:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/09 21:21:33 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/
BitcoinExchange::BitcoinExchange(void): _database("data.csv"), _datafile(""){
	if (isValidFile(this->_database)){
		_dataToMap(this->_database, ',', &(this->_db));
	} else
		throw FileNotFound();
}

BitcoinExchange::BitcoinExchange(std::string database): _database(database), _datafile(""){	
	if (isValidFile(this->_database)){
		_dataToMap(this->_database, ',', &(this->_db));
	} else
		throw FileNotFound();
}

BitcoinExchange::~BitcoinExchange() {
	if (this->getDB())
		this->getDB()->clear();
	if (this->getDF())
		this->getDF()->clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

/************************************************
 *               Operator function              *
 ************************************************/
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other) {
			if (this != &other){
				this->_database = other._database;
				this->_datafile = other._datafile;
				if (this->getDB())
					this->getDB()->clear();
				if (this->getDF())
					this->getDF()->clear();
				this->_db = other._db;
				this->_df = other._df;
			}
			return (*this);
}

/************************************************
 *              getter & setter                 *
 ************************************************/
void BitcoinExchange::putDatafile(std::string argv){
	this->_datafile = argv;
}

std::string BitcoinExchange::getDatabase() const {
	return (this->_database);
}

std::string BitcoinExchange::getDatafile() const {
	return (this->_datafile);
} 

std::unordered_multimap<std::string, float> *BitcoinExchange::getDB() const {
	return const_cast<std::unordered_multimap<std::string, float> *>(&this->_db);
}

std::unordered_multimap<std::string, float> *BitcoinExchange::getDF() const {
	return const_cast<std::unordered_multimap<std::string, float> *>(&this->_df);
}
/************************************************
 *               Member function                *
 ************************************************/

void	BitcoinExchange::execExchange(std::string argv){
	if (isValidFile(argv)){
		this->putDatafile(argv);
		if (this->getDF())
			this->getDF()->clear();
		_dataToMap(this->getDatafile(), '|', &(this->_df));
	} else
		throw FileNotFound();
	std::unordered_multimap<std::string, float> *df =  this->getDF();
	std::unordered_multimap<std::string, float> *db =  this->getDB();
	for (std::unordered_multimap<std::string, float>::iterator it = df->begin(); it != df->end(); ++it){
		if (it->second == -1)
			std::cout << "Error: not a positive number." << std::endl;
		else if (it->second == -2)
			std::cout << "Error: too large a number." << std::endl;
		else if (it->second == -3)
			std::cout << "Error: bad input => " << it->first << std::endl;
		else {
			std::cout << it->first <<" => "<< it->second;
			for (std::unordered_multimap<std::string, float>::iterator its = db->begin(); its != db->end(); ++its){
				if (it->first == its->first)
					std::cout << " = "<< its->second;
			}
			std::cout << std::endl;
		}
	}
}

void BitcoinExchange::_dataToMap(std::string data, char ch, std::unordered_multimap<std::string, float> *map) {
	std::ifstream file(data);
	std::string line;
	std::string date;
	float value;
	
	if (!file.is_open())
		throw BitcoinExchange::FileNotFound();
	while (std::getline(file, line)) {
		date = trim(line.substr(0, line.find(ch)));
		if (date == "date")
			continue;
		if (isValidDate(date) && line.find(ch) != std::string::npos){
			std::string tmp = trim(line.substr(line.find(ch) + 1, line.length()));
			value = atof(tmp.c_str());
			if (isValidValue(&value, ch))
				*map->insert(std::make_pair(date, value));
		} else {
			value = -3;
			*map->insert(std::make_pair(date, value));
		}
	}
	file.close();
}

/************************************************
 *               Utility function               *
 ************************************************/
bool isValidFile(std::string file){
	std::ifstream fileStatus(file);
	if (!fileStatus.is_open())
		return (false);
	fileStatus.close();
	return (true);
}

bool isLeapYear(int year) {
    // Leap year if divisible by 4
    // Exception: If divisible by 100, must also be divisible by 400
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool has30Days(int month) {
    // Check if the month has 30 days
    return (month == 4 || month == 6 || month == 9 || month == 11);
}

bool isValidDate(std::string date){
	if (date.length() != 10 && date.at(4) != '-' && date.at(7) != '-')
		return (false);
	int	y = atoi(date.substr(0, 4).c_str());
	int	m = atoi(date.substr(5, 2).c_str());
	int	d = atoi(date.substr(8, 2).c_str());
	if (y < 2000  || y > 2022 || m < 0 || m > 12 || d < 0 || d > 31)
		return (false);
	if (m == 2 && (!isLeapYear(y) && d >= 29))
		return (false);
	if (has30Days(m) && d > 30)
		return (false);
	return (true);
}

bool isValidValue(float * value, char ch){
	if ( ch == ','){
		if (*value < 0)
			return (false);
		return (true);
	} else {
		if (*value < 0)
			*value = -1;
		else if (*value > 1000)
			*value = -2;	
	}
	return (true);
}

std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    size_t end = s.find_last_not_of(" \t\n\r\f\v");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return s.substr(start, end - start + 1);
}