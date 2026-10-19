/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:35 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/19 18:56:24 by asauvage         ###   ########.fr       */
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
# include <sys/time.h>
# include <iomanip>

struct	Element {
	int	value;
	std::vector<Element> losers;
};

struct	PendElement {
	Element	loser;
	int		winner_value;
};

class	Pmerge {
	public:
		Pmerge( char **str );
		Pmerge( const Pmerge& obj );
		Pmerge&	operator=( const Pmerge& rhs );
		~Pmerge();
		bool						verifInt(char *str);
		void						Sort();
		void						Dichotomie( std::vector<Element>& Dichotomie, int i, Element search );
		void						Dichotomie( std::deque<Element>& Dichotomie, int i, Element search );
		int							DichotomieIndex( std::vector<Element>& Dichotomie, int search);
		int							DichotomieIndex( std::deque<Element>& Dichotomie, int search);
		std::vector<Element>		FordJohnson( const std::vector<Element>& container );
		std::deque<Element>			FordJohnson( const std::deque<Element>& container );
		std::vector<PendElement>	ExtractLosers( std::vector<Element>& main_chain );
		std::deque<PendElement>		ExtractLosers( std::deque<Element>& main_chain );
		void						DisplayContainer();
	private:
		Pmerge();
		std::set<int>			double_;
		std::vector<Element>	vect_;
		std::deque<Element>		deque_;
};

#endif