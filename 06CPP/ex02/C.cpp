/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:30 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:22:10 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "C.hpp"	

C::C(void): _type("C")
{
	return ;
}

C::C(C const &other)
{
	*this = other;
	return ;
}

C::~C(void)
{
	return ;
}

C &C::operator=(C const &other)
{
	(void)other;
	return (*this);
}

std::string C::getType() const
{
	return (this->_type);
}



