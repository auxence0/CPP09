/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:14:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/02 17:30:35 by asauvage         ###   ########.fr       */
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

Parser::Parser( const Parser& obj ) {
	btc_csv_ = obj.btc_csv_;
}


Parser&	Parser::operator=( const Parser& rhs ) {
	if (this != &rhs) {
		btc_csv_ = rhs.btc_csv_;
	}
	return *this;
}

Parser::~Parser() {
}

void	Parser::VerifDate() {
	
}


void	Parser::ParseLine( const std::string& line ) {
	std::istringstream	stream_line(line);

	if (!(stream_line >> date_ >> sep_ >> value_ >> smth_)) {
		std::cout << "Error: bad input => " << line << "\n";
	}
	try {
		
	}
}

void	Parser::FirstLineCheck( std::ifstream* input ) {
	std::string	line;
	getline(*input, line);
	std::istringstream	first_line(line);

	if (!(first_line >> date_ >> sep_ >> value_ >> smth_)) {
		std::cout << "Error: bad input => " << line << "\n";
	}
	if (date_ != "date" || sep_ != '|' || value_ != "value" || smth_) {
		ParseLine(line);
	}
}

void	Parser::ReadInput( const std::string& str ) {
	std::ifstream	input(str.c_str());
	if (!input)
		throw	std::runtime_error("Error: could not open file.");

	FirstLineCheck(&input);
}
