/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:07:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/07 16:09:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);
	Bureaucrat c("C", 151);
	Bureaucrat d("D", 0);

	std::cout << a.getName() << " : " << a.getGrade() << std::endl;
	std::cout << b.getName() << " : " << b.getGrade() << std::endl;
	std::cout << c.getName() << " : " << c.getGrade() << std::endl;
	std::cout << d.getName() << " : " << d.getGrade() << std::endl;
	return (0);
}

// int main()
// {
// 	try {
// 	throw 'a';
// 	}
// 	catch (int x) {
// 		cout << "Caught " << x;
// 	}
// 	catch (...) {
// 		cout << "Default Exception\n";
// 	}
// 	return 0;
// }


// int main()
// {
// 	try {
// 	throw 10;
// 	}
// 	catch (char *excp) {
// 		cout << "Caught " << excp;
// 	}
// 	catch (...) {
// 		cout << "Default Exception\n";
// 	}
// 	return 0;
// }


// int main()
// {
// int x = -1;

// // Some code
// cout << "Before try \n";
// try {
// 	cout << "Inside try \n";
// 	if (x < 0)
// 	{
// 		throw x;
// 		cout << "After throw (Never executed) \n";
// 	}
// }
// catch (int x ) {
// 	cout << "Exception Caught \n";
// }

// cout << "After catch (Will be executed) \n";
// return 0;
// }
