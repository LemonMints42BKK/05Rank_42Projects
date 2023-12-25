/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:09:49 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 07:48:05 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer &operator=(Serializer const &other);

		static uintptr_t serialize(Data* ptr);	//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data *deserialize(uintptr_t raw);	//It takes an unsigned integer parameter and converts it to a pointer to Data.
};
