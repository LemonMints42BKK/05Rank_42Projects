/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:48 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:17:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "B.hpp"

B::B(void): _type("B")
{
	return ;
}

B::B(B const &other)
{
	*this = other;
	return ;
}

B::~B(void)
{
	return ;
}

B &B::operator=(B const &other)
{
	(void)other;
	return (*this);
}

std::string B::getType() const
{
	return (this->_type);
}	