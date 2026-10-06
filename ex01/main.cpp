/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:38:51 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/06 14:50:27 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Usage: exec <arg>\n";
		return 1;
	}

	try {
		RPN	rpn(av[1]);
		rpn.calc_res();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}
