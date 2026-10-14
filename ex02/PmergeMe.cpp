/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:54 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/14 16:10:31 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

Pmerge::Pmerge() {}

Pmerge::Pmerge( char **str ) {
	errno = 0;
	size_t	i(1);
	long	num;

	while (str[i]) {
		if (verifInt(str[i]) == false)
			throw	std::runtime_error("Error: input");
		num = strtol(str[i], NULL, 10);
		if (errno == ERANGE || num < 0 || num > std::numeric_limits<int>::max())
			throw	std::runtime_error("Error: input");
		if (double_.find(num) != double_.end())
			throw	std::runtime_error("Error: Duplicate number");
		double_.insert(num);
		Element	elt = {num};
		vect_.push_back(elt);
		deque_.push_back(elt);
		i++;
	}
}

Pmerge::Pmerge( const Pmerge& obj ) {
	double_ = obj.double_;
}

Pmerge&	Pmerge::operator=( const Pmerge& rhs ) {
	if (this != &rhs) {
		double_ = rhs.double_;
	}
	return *this;
}

Pmerge::~Pmerge() {}

bool	Pmerge::verifInt(char *str) {
	bool	has_int(false);
	size_t	i(0);

	while (isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (isdigit(str[i])) {
		has_int = true;
		i++;
	}
	while (isspace(str[i]))
		i++;
	if (str[i] == '\0' && has_int == true)
		return true;
	return false;
}

std::vector<Element>	Pmerge::FordJohnson( const std::vector<Element>& container ) {
	int	last_elt(-1);
	if (container.size() <= 1)
		return container;
	if (container.size() % 2)
		last_elt = container.pop_back().Value;
	while ()
}

void	Pmerge::Sort() {
	FordJohnson(vect_);
}
