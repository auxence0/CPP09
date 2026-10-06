/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:04:16 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/06 15:01:42 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( const std::string& arg ) {

	size_t	i = arg.find_first_not_of(" \t\n\r\v\f", 0);

	while (std::string::npos != i) {
		if (!isdigit(arg[i]) && std::string("*/+-").find(arg[i]) == std::string::npos)
			throw	std::runtime_error("Error: bad input");
		else if (!isspace(arg[i + 1]) && arg[i + 1] != '\0')
			throw	std::runtime_error("Error: bad input");
		i = arg.find_first_not_of(" \t\n\r\v\f", i + 1);
	}
	str_ = arg;
}

RPN::RPN( const RPN& obj ) {
	s_ = obj.s_;
}

RPN&	RPN::operator=( const RPN& rhs ) {
	if (this != &rhs) {
		s_ = rhs.s_;
	}
	return *this;
}

RPN::~RPN() {}

bool	RPN::do_op( char op ) {
	if ( s_.size() < 2) {
		std::cerr << "Error: Missing number for operation\n";
		return false;
	}
	long long	num2(s_.top());
	s_.pop();
	long long	num1(s_.top());
	s_.pop();
	long long	res(0);
	switch (op) {
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num1 / num2;
			break;
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num1 - num2;
			break;
	}
		if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max()) {
			std::cerr << "Error: res of some operation overflow\n";
			return false;
		}
	s_.push(static_cast<int>(res));
	return true;
}

void	RPN::calc_res() {

	size_t	i = str_.find_first_not_of(" \t\n\r\v\f", 0);

	while (std::string::npos != i) {
		if (std::string("*/+-").find(str_[i]) != std::string::npos) {
			if (do_op(str_[i]) == false)
				return;
		}
		else
			s_.push(str_[i] - '0');
		i = str_.find_first_not_of(" \t\n\r\v\f", i + 1);
	}
	if (s_.size() != 1)
		std::cerr << "Error: Operation incomplete: " << s_.size() << " numbers still remaining ont the stack\n";
	else
		std::cout << s_.top() << "\n";
}
