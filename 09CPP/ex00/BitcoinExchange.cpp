/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:29:10 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/05 13:51:45 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/
BitcoinExchange::BitcoinExchange(void): _database("data.csv"), _datafile("") , _db(NULL), _df(NULL){
	if (isValidFile(this->_database)){
		this->_db = new std::map<std::string, double>;
		_dataToMap(this->_database, ',', this->_db);
	} else
		throw FileNotFound();
	std::cout << "constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string database): _database(database), _datafile(""), _db(NULL), _df(NULL){	
	if (isValidFile(this->_database)){
		this->_db = new std::map<std::string, double>;
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

std::map<std::string, double> *BitcoinExchange::getDB() const {
	return (this->_db);
}

std::map<std::string, double> *BitcoinExchange::getDF() const {
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
		this->_df = new std::map<std::string, double>;
		_dataToMap(this->getDatafile(), '|', this->_df);
	} else
		throw FileNotFound();
}

void BitcoinExchange::_dataToMap(std::string data, char ch, std::map<std::string, double> *map) {
	std::ifstream file(data);
	std::string line;
	std::string date;
	double  value;
	
	if (!file.is_open())
		throw BitcoinExchange::FileNotFound();
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(ch));
		if (isValidDate(date)){
			value = atof(line.substr(line.find(ch) + 1, line.length()).c_str());
			// if (isValidValue(value))
			map->insert(std::pair<std::string, double>(date,  value));
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

bool isValidValue(double value){
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}