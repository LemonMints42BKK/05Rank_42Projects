/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:16:57 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 10:17:35 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"

A::A(void): _type("A")
{
	return ;
}

A::A(A const &other)
{
	*this = other;
	return ;
}

A::~A(void)
{
	return ;
}

A &A::operator=(A const &other)
{
	(void)other;
	return (*this);
}

std::string A::getType() const
{
	return (this->_type);
}	
