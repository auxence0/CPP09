/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:02:32 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/01 16:34:35 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <arg>\n";
		return EXIT_FAILURE;
	}
	Parser	Parse;
	for (std::map<std::string, float>::iterator	it = Parse.btc_csv_.begin(); it != Parse.btc_csv_.end(); ++it) {
		std::cout << "key: " << it->first << "value: " << it->second << "\n";
	}
}
