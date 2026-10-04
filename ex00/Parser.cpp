/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:14:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/04 18:04:26 by asauvage         ###   ########.fr       */
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

bool	Parser::VerifDate( const std::string& line ) {
	std::istringstream	date_stream(date_);
	int		Y, M, D;
	char	sep1, sep2;

	if (!(date_stream >> Y >> sep1 >> M >> sep2 >> D) || !(date_stream.eof())) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (sep1 != '-' || sep2 != '-') {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	else if (M < 1 || M > 12 || D < 1) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	bool		isLeapY = ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0));
	const int	DayinM[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			MaxD = DayinM[M];
	if (M == 2 && isLeapY)
		MaxD = 29;
	if (D > MaxD) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (Y < 2009 || (Y == 2009 && M == 1 && D < 2)) {
		std::cout << "Error: Date is too old." << "\n";
		return false;
	}
	return true;
}

bool	Parser::VerifValue( const std::string& line ) {

	size_t i = 0;
	if (value_.empty()) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (value_[i] == '+' || value_[i] == '-')
		i++;
	if (value_[i] == '.') {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (value_[value_.length() - 1] == '.') {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (i == value_.length()) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}

	bool	has_dot = false;
	bool	has_digit = false;
	for (; value_[i]; ++i) {
		if (value_[i] == '.') {
			if (has_dot) {
				std::cout << "Error: bad input => " << line << "\n";
				return false;
			}
			has_dot = true;
		}
		else if (std::isdigit(value_[i])) {
			has_digit = true;
		}
		else {
			std::cout << "Error: bad input => " << line << "\n";
			return false;
		}
	}
	if (has_digit == false) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}

	errno = 0;
	char	*endptr;
	float_value_ = std::strtof(value_.c_str(), &endptr);
	if (value_.c_str() == endptr || *endptr || errno == ERANGE) {
		std::cout << "Error: bad input => " << line << "\n";
		return false;
	}
	if (float_value_ > 1000.0f) {
		std::cout << "Error: too large a number.\n";
		return false;
	}
	if (float_value_ < 0.0f) {
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	return true;
}

void	Parser::ParseLine( const std::string& line ) {
	std::istringstream	stream_line(line);

	if (!(stream_line >> date_ >> sep_ >> value_ >> smth_)) {
		std::cout << "Error: bad input => " << line << "\n";
	}
	if (!VerifDate(line))
		return;
	if (!VerifValue(line));
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
