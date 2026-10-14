/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:35 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/14 15:55:50 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <set>
# include <string>
# include <limits>
# include <exception>
# include <vector>
# include <deque>
# include <cstdlib>

struct	Element {
	int	Value;
	std::vector<Element> losers;
};

class	Pmerge {
	public:
		Pmerge( char **str );
		Pmerge( const Pmerge& obj );
		Pmerge&	operator=( const Pmerge& rhs );
		~Pmerge();
		bool	verifInt(char *str);
		std::vector<Element>	FordJohnson( const std::vector<Element>& container );
		void	Sort();
	private:
		Pmerge();
		std::set<int>			double_;
		std::vector<Element>	vect_;
		std::deque<Element>		deque_;
};

#endif