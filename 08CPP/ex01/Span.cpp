/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:55:19 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/07 22:20:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n){
	if (n == 0)
		throw std::out_of_range("Can't have 0 size");
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {
}

Span &Span::operator=(Span const &copy) {
	if (this != &copy)
	{
		this->_n = copy._n;
		this->_vec = copy._vec;
	}
	return (*this);
}

unsigned int Span::getN() const {
	return (this->_n);
}

std::vector<int> *Span::getVec() const {
	return (const_cast<std::vector<int>*>(&this->_vec));
}

void Span::addNumber(int n) {
	if (this->getVec()->size() >= this->getN())
		throw isFull();
	this->getVec()->push_back(n);
}	

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->getVec()->size() + std::distance(begin, end) > this->getN())
		throw isFull();
	this->getVec()->insert(this->getVec()->end(), begin, end);
}

int Span::shortestSpan() {
	std::vector<int> *container = this->getVec();
	if (container->size() < 2)
		throw noSpan();
	std::sort(container->begin(), container->end());
	int min = container->at(1) - container->at(0);
	for (unsigned int i = 2; i < container->size(); i++)
	{
		int tmp = container->at(i) - container->at(i - 1);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}	

int Span::longestSpan() {
	std::vector<int> *container = this->getVec();
	if (container->size() < 2)
		throw noSpan();
	std::sort(container->begin(), container->end());
	return (container->at(container->size() - 1) - container->at(0));
}	

std::ostream & operator<<( std::ostream & str, Span const & rhs) {
	std::vector<int>::iterator it;
	str << "[";
	for (size_t i = 0 ; i < rhs.getVec()->size(); ++i)
	{
		str << rhs.getVec()->at(i);
		if (i < rhs.getVec()->size() - 1)
			str << ", ";
	}
	str << "]";
	return str;
}

