/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:14:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/01 16:34:08 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

Parser::Parser() {
	std::ifstream	infile("data.csv");
	if (!infile)
		throw	std::runtime_error("Can't open csv file");

	std::string	line;
	while (getline(infile, line)) {
		std::string	key = line.substr(0, 10);
		std::string	value_str = line.substr(11);
		float	value = std::strtof(value_str.c_str(), NULL);
		btc_csv_.insert(std::make_pair(key, value));
	}
}

Parser::~Parser() {
}
