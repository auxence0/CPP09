/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:35 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/23 12:31:06 by asauvage         ###   ########.fr       */
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

struct	Element_v {
	int	value;
	std::vector<Element_v> losers;
};

struct	Element_d {
	int	value;
	std::vector<Element_d> losers;
};

struct	PendElement_v {
	Element_v	loser;
	int			winner_value;
};

struct	PendElement_d {
	Element_d	loser;
	int			winner_value;
};

class	Pmerge {
	public:
		Pmerge( char **str );
		Pmerge( const Pmerge& obj );
		Pmerge&	operator=( const Pmerge& rhs );
		~Pmerge();
		bool						verifInt(char *str);
		void						Sort();
		void						Dichotomie( std::vector<Element_v>& Dichotomie, int i, Element_v search );
		void						Dichotomie( std::deque<Element_d>& Dichotomie, int i, Element_d search );
		int							EndBound( std::vector<Element_v>& Dichotomie, int search);
		int							EndBound( std::deque<Element_d>& Dichotomie, int search);
		std::vector<Element_v>		FordJohnson( const std::vector<Element_v>& container );
		std::deque<Element_d>		FordJohnson( const std::deque<Element_d>& container );
		std::vector<PendElement_v>	ExtractLosers( std::vector<Element_v>& main_chain );
		std::deque<PendElement_d>	ExtractLosers( std::deque<Element_d>& main_chain );
		void						DisplayContainer();
	private:
		Pmerge();
		std::set<int>			double_;
		std::vector<Element_v>	vect_;
		std::deque<Element_d>	deque_;
};

#endif