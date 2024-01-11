/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:36 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/09 23:54:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression): _expr(expression), _result(0), _x(0), _y(0){
	this->_op[0] = '+';
	this->_op[1] = '-';
	this->_op[2] = '*';
	this->_op[3] = '/';
	this->_func[0] = &RPN::_add;
	this->_func[1] = &RPN::_sub;
	this->_func[2] = &RPN::_mul;
	this->_func[3] = &RPN::_div;
	this->_parse();
	return ;
}

RPN::RPN(RPN const &rhs) {
	*this = rhs;
}

RPN::~RPN() {
	return ;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this != &rhs){
		this->_expr = rhs.getExpr();
		this->_result = rhs.getResult();
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_op[0] = rhs._op[0];
		this->_op[1] = rhs._op[1];
		this->_op[2] = rhs._op[2];
		this->_op[3] = rhs._op[3];
		this->_func[0] = rhs._func[0];
		this->_func[1] = rhs._func[1];
		this->_func[2] = rhs._func[2];
		this->_func[3] = rhs._func[3];
	}
	return (*this);
}

void printStack(std::stack<char> stk){
	std::cout << "Stack: ";
	for (std::stack<char> dump = stk; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";
	std::cout << std::endl;
}

void RPN::_parse(){
	std::string tmp = this->getExpr();
	for(std::string::reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it){
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%')
			this->_token.push(*it);
		else if (*it >= '0' && *it <= '9')
			this->_token.push(*it);
		else if (*it != ' ')
			throw RPN::InvalidExpression();
	}
	while (!this->_token.empty()){
		
		if (this->_token.top() >= '0' && this->_token.top() <= '9')
			this->_tmp.push(this->_token.top() - '0');
		else if (this->_token.top() == '+' || this->_token.top() == '-' || this->_token.top() == '*' || this->_token.top() == '/' || this->_token.top() == '%'){
			if (this->_tmp.size() < 2)
				throw RPN::InvalidExpression();
			putY(this->_tmp.top());
			this->_tmp.pop();
			putX(this->_tmp.top());
			this->_tmp.pop();
			for (int i = 0; i < 4; i++){
				if (this->_token.top() == this->_op[i])
					(this->*_func[i])();
			}
			this->_tmp.push(this->_result);
		}
		this->_token.pop();
	}
	if (this->_tmp.size() != 1)
		throw RPN::InvalidExpression();
	return ;
}

void RPN::_add() {
	this->_result = this->_x + this->_y;
	return ;
}

void RPN::_sub() {
	this->_result = this->_x - this->_y;
	return ;
}

void RPN::_mul() {
	this->_result = this->_x * this->_y;
	return ;
}

void RPN::_div() {
	this->_result = this->_x / this->_y;
	return ;
}

void RPN::putX(int x) {
	this->_x = x;
	return ;
}

void RPN::putY(int y) {
	this->_y = y;
	return ;
}

std::string RPN::getExpr() const {
	return (this->_expr);
}

int RPN::getResult() const {
	return (this->_result);
}

int RPN::result(){
	return (this->getResult());
}