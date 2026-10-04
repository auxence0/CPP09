/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:26:30 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/04 18:37:59 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <cstdlib>
# include <string>
# include <fstream>
# include <exception>
# include <sstream>

class	Parser {
	public:
		Parser();
		Parser( const Parser& obj );
		Parser&	operator=( const Parser& rhs );
		~Parser();

		void	ParseLine( const std::string& line );
		void	ReadInput( const std::string& str );
		void	FirstLineCheck( std::string& line );
		bool	VerifDate( const std::string& line );
		bool	VerifFormatDate();		
		bool	VerifValue( const std::string& line );
		void	DisplayLine();
	private:
		std::map<std::string, float>	btc_csv_;
		std::string	date_;
		std::string	value_;
		char		sep_;
		char		smth_;
		float		float_value_;
};

#endif