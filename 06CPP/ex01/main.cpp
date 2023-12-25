/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:36:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/25 07:45:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void){
	Data message;
	message.value = "Hello 42 Bangkok!";
	
	Data *addr1 = &message;
	message.key = Serializer::serialize(addr1);
	
	/*used static deserialize as getter&putter of Data type valuables*/
	Data *addr2 = Serializer::deserialize(message.key);
	Data *addr3 = Serializer::deserialize(Serializer::serialize(addr1));
	
	std::cout << "addr1 Message: " << addr1->value << std::endl;
	std::cout << "addr2 Message: " << addr2->value << std::endl;
	std::cout << "addr3 Message: " << addr3->value << std::endl;

	addr3->value = "Merry X'mas!";
	std::cout << "addr1 Message: " << addr1->value << std::endl;
	return (0);
}