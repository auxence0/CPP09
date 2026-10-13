/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:19:32 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/13 16:31:39 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	Parser(char **str) {
	size_t	i(0);
	errno = 0;

	while (str[i]) {
		
	}
}

int	main(int ac, char **av) {
	if (ac < 3) {
		std::cerr << "Error: Need at least two arguments to perform a sort.\n";
		return 1;
	}
	if (Parser(&av[1]) == false)
		return 1;
}
