/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:54 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/15 18:03:51 by asauvage         ###   ########.fr       */
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
		Element	elt;
		elt.value = num;
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

void	Pmerge::Dichotomie( std::vector<Element>& Dichotomie, int i, Element search ) {
	int	mid(0);
	int	start(0);
	int	end(i);

	while (start <= end) {
		mid = (start + end) / 2;
		if (Dichotomie[mid].value > search.value)
			end = mid - 1;
		else
			start = mid + 1;
	}
	Dichotomie.insert(Dichotomie.begin() + start, search);
}

int	Pmerge::DichotomieIndex( std::vector<Element>& Dichotomie, int search ) {
	int	mid(0);
	int	start(0);
	int	end(Dichotomie.size() - 1);

	while (start <= end) {
		mid = (start + end) / 2;
		if (Dichotomie[mid].value > search)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

std::vector<PendElement>	Pmerge::ExtractLosers( std::vector<Element>& main_chain ) {
	size_t						i(0);
	std::vector<PendElement>	pend;

	while (i < main_chain.size()) {
		Element	loser_ = main_chain[i].losers.back();
		PendElement	PendElt;
		PendElt.loser = loser_;
		PendElt.winner_value = main_chain[i].value;
		pend.push_back(PendElt);
		main_chain[i++].losers.pop_back();
	}
	return pend;
}

std::vector<Element>	Pmerge::FordJohnson( const std::vector<Element>& container ) {
	Element	last_elt;
	bool	odd(false);

	if (container.size() <= 1)
		return container;
	if (container.size() % 2) {
		odd = true;
		last_elt = container.back();
	}

	std::vector<Element>	new_container;

	for (size_t	i(0); i < container.size() - odd; i+= 2) {
		if (container[i].value > container[i + 1].value) {
			Element	Winner = container[i];
			Winner.losers.push_back(container[i + 1]);
			new_container.push_back(Winner);
		}
		else {
			Element	Winner = container[i + 1];
			Winner.losers.push_back(container[i]);
			new_container.push_back(Winner);
		}
	}
	new_container = FordJohnson(new_container);

	size_t	Jnm1(1);
	size_t	Jnm2(0);
	size_t	Jn(1);
	size_t	i(0);
	size_t	size_container = new_container.size();

	std::vector<PendElement>	losers_lst = ExtractLosers(new_container);
	std::vector<PendElement>::iterator	it(losers_lst.begin());
	while (it != losers_lst.end()) {
		std::cout << it->loser.value << ", ";
		++it;
	}
	std::cout << "\n";
	while ( Jnm1 <= size_container ) {
		if (Jn == 1) {
			new_container.insert(new_container.begin(), losers_lst[i].loser);
			Jnm2 = Jnm1;
			Jnm1 = Jn;
			Jn = Jnm2 * 2 + Jnm1;
			if (Jn - 1 >= losers_lst.size())
				i = losers_lst.size() - 1;
			else
				i = Jn - 1;
		}
		else if (i > Jnm2) {
			Dichotomie(new_container, DichotomieIndex(new_container, losers_lst[i].winner_value), losers_lst[i].loser);
			i--;
		}
		else {
			Jnm2 = Jnm1;
			Jnm1 = Jn;
			Jn = Jnm2 * 2 + Jnm1;
			if (Jn - 1 >= losers_lst.size())
				i = losers_lst.size() - 1;
			else
				i = Jn - 1;
		}
	}

	if (odd == true)
		Dichotomie(new_container, new_container.size() - 1, last_elt);
	return new_container;
}

void	Pmerge::Sort() {
	vect_ = FordJohnson(vect_);
	std::vector<Element>::iterator	it(vect_.begin());
	while (it != vect_.end()) {
		std::cout << it->value << ", ";
		++it;
	}
	std::cout << "\n";
}
