/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:02:32 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/02 17:24:34 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file.\n";
		return EXIT_FAILURE;
	}
	try {
		Parser	Parse;
		Parse.ReadInput(av[1]);
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
