/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:09:46 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 07:17:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){
	return ;
}
Serializer::Serializer(Serializer const &src){
	*this = src;
	return ;
}
Serializer::~Serializer(void){
	return ;
}

Serializer & Serializer::operator=(Serializer const &other){
	if (this != &other)
		*this = other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw){
		reinterpret_cast<Data *>(raw)->key = raw;
	return (reinterpret_cast<Data *>(raw));
}