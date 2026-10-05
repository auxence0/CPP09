/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:04:16 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/05 16:59:54 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( const std::string& arg ) {

	size_t	i = arg.find_first_not_of(" \t\n\r\v\f", 0);

	while (std::string::npos != i) {
		std::cout << "idx: " << i << "\n";
		if (!isdigit(arg[i]) && std::string("*/+-").find(arg[i]) == std::string::npos)
			throw	std::runtime_error("bad input");
		else if (!isspace(arg[i + 1]) && arg[i + 1] != '\0')
			throw	std::runtime_error("bad input");
		i = arg.find_first_not_of(" \t\n\r\v\f", i);
	}
}

RPN::RPN( const RPN& obj ) {
	s = obj.s;
}

RPN&	RPN::operator=( const RPN& rhs ) {
	if (this != &rhs) {
		s = rhs.s;
	}
	return *this;
}

RPN::~RPN() {}


