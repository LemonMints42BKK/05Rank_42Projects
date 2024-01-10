/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:32 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/09 23:27:44 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN {
	typedef void (RPN::*do_op)();
	private:
		std::string			_expr;
		std::stack<char>	_token;
		std::stack<int>		_tmp;
		int					_result;
		int					_x;
		int					_y;
		char				_op[4];
		do_op				_func[4];
		
		RPN();
		void _add();
		void _sub();
		void _mul();
		void _div();
		void _parse();
	public:
		RPN(std::string expression);
		RPN(RPN const &rhs);
		~RPN();
		
		RPN &operator=(RPN const &rhs);
		
		void		putX(int x);
		void		putY(int y);
		std::string getExpr() const;
		int			getResult() const;
		
		int result();
	
	class InvalidExpression : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Error");
			}
	};
};
