/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:55:19 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/03 21:45:17 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) , _vec(NULL){
	if (n == 0)
		throw std::out_of_range("Can't have 0 size");
	this->_vec = new std::vector<int>;
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {
	if (!this->_vec->empty())
		this->_vec->clear();
}

Span &Span::operator=(Span const &copy) {
	if (this != &copy)
	{
		this->_n = copy._n;
		if (this->_vec)
			this->_vec->clear();
		this->_vec = new std::vector<int>;
		if (!copy._vec->empty()){
			for(unsigned int i = 0; i < copy._vec->size(); i++)
				this->_vec->push_back(copy._vec->at(i));
		}
	}
	return (*this);
}

unsigned int Span::getN() const {
	return (this->_n);
}

std::vector<int> & Span::getVec() const {
	return (*this->_vec);
}

void Span::addNumber(int n) {
	std::vector<int> container = this->getVec();
	if (container.size() >= this->getN())
		throw isFull();
	this->_vec->push_back(n);
}	

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int> container = this->getVec();
	if (container.size() >= this->getN())
		throw isFull();
	this->_vec->insert(this->_vec->end(), begin, end);
}

int Span::shortestSpan() {
	std::vector<int> container = this->getVec();
	if (container.size() < 2)
		throw noSpan();
	std::sort(container.begin(), container.end());
	int min = container.at(1) - container.at(0);
	for (unsigned int i = 2; i < container.size(); i++)
	{
		int tmp = container.at(i) - container.at(i - 1);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}	

int Span::longestSpan() {
	std::vector<int> container = this->getVec();
	if (container.size() < 2)
		throw noSpan();
	std::sort(container.begin(), container.end());
	return (container.at(container.size() - 1) - container.at(0));
}	

std::ostream & operator<<( std::ostream & str, Span const & rhs) {
	std::vector<int>::iterator it;
	std::vector<int> container = rhs.getVec();
	str << "[";
	for (size_t i = 0 ; i < container.size(); ++i)
	{
		str << container.at(i);
		if (i < container.size() - 1)
			str << ", ";
	}
	str << "]";
	return str;
}

