/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:29:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 20:45:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/
BitcoinExchange::BitcoinExchange(void): _database("data.csv"), _datafile("") , _db(NULL), _df(NULL){
	if (isValidFile(this->_database)){
		this->_db = new std::map<std::string, float>;
		_dataToMap(this->_database, ',', this->_db);
	} else
		throw FileNotFound();
	std::cout << "constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string database): _database(database), _datafile(""), _db(NULL), _df(NULL){	
	if (isValidFile(this->_database)){
		this->_db = new std::map<std::string, float>;
		_dataToMap(this->_database, ',', this->_db);
	} else
		throw FileNotFound();
	std::cout << "constructor" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	if (this->getDB())
		this->getDB()->clear();
	if (this->getDF())
		this->getDF()->clear();
	std::cout << "deconstructor" << std::endl;
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

std::map<std::string, float> *BitcoinExchange::getDB() const {
	return (this->_db);
}

std::map<std::string, float> *BitcoinExchange::getDF() const {
	return (this->_df);
}
/************************************************
 *               Member function                *
 ************************************************/

void	BitcoinExchange::execExchange(std::string argv){
	if (isValidFile(argv)){
		this->putDatafile(argv);
		if (this->getDF())
			this->getDF()->clear();
		this->_df = new std::map<std::string, float>;
		_dataToMap(this->getDatafile(), '|', this->_df);
	} else
		throw FileNotFound();
}

void BitcoinExchange::_dataToMap(std::string data, char ch, std::map<std::string, float> *map) {
	std::ifstream file(data);
	std::string line;
	std::string date;
	float value;
	
	if (!file.is_open())
		throw BitcoinExchange::FileNotFound();
	while (std::getline(file, line)) {
		date = trim(line.substr(0, line.find(ch)));
		if (isValidDate(date)){
			std::string tmp = trim(line.substr(line.find(ch) + 1, line.length()));
			value = atof(tmp.c_str());
			std::cout << "Original string: " << tmp << std::endl;
    		std::cout << std::fixed << std::setprecision(2)<< "Converted value: " << value << std::endl;
			// if (isValidValue(value))
			map->insert(std::pair<std::string, float>(date,  std::fixed << std::setprecision(2)<< value));
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

bool isValidDate(std::string date){
	if (date == "date")
		return (false);
	if (date.length() == 10 && date.at(4) == '-' && date.at(7) == '-'){
		
	}
	return (true);
}

bool isValidValue(float value){
	if (value < 0 || value > 1000)
		return (false);
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