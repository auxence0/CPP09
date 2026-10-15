/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:19:32 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/15 15:26:46 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 3) {
		std::cerr << "Error: Need at least two arguments to perform a sort.\n";
		return 1;
	}
	try {
		Pmerge	merge(av);
		merge.Sort();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}
