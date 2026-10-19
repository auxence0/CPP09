/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:05:54 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/19 19:09:23 by asauvage         ###   ########.fr       */
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

void	Pmerge::DisplayContainer() {
	std::vector<Element>::iterator	it(vect_.begin());
	size_t	nb_num(0);

	while (it != vect_.end() && nb_num++ < 15) {
		std::cout << " " << it->value;
		++it;
	}
	if (it != vect_.end())
		std::cout << " [...]";

	std::cout << "\n";
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

	std::vector<PendElement>	losers_lst = ExtractLosers(new_container);
	if (!losers_lst.empty())
		new_container.insert(new_container.begin(), losers_lst[0].loser);
	
	size_t	Jnm1(3);
	size_t	Jnm2(1);
	size_t	last_insert(0);	
	while (last_insert + 1 < losers_lst.size()) {
		size_t	upper_bound = Jnm1 - 1;
		if (upper_bound >= losers_lst.size())
			upper_bound = losers_lst.size() - 1;
		
		for (size_t	idx = upper_bound; idx > last_insert; --idx)
			Dichotomie(new_container, DichotomieIndex(new_container, losers_lst[idx].winner_value), losers_lst[idx].loser);

		last_insert = upper_bound;
		size_t	Jn = 2 * Jnm2 + Jnm1;
		Jnm2 = Jnm1;
		Jnm1 = Jn;
	}

	if (odd == true)
		Dichotomie(new_container, new_container.size() - 1, last_elt);
	return new_container;
}

void	Pmerge::Dichotomie( std::deque<Element>& Dichotomie, int i, Element search ) {
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

int	Pmerge::DichotomieIndex( std::deque<Element>& Dichotomie, int search ) {
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

std::deque<PendElement>	Pmerge::ExtractLosers( std::deque<Element>& main_chain ) {
	size_t						i(0);
	std::deque<PendElement>	pend;

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

std::deque<Element>	Pmerge::FordJohnson( const std::deque<Element>& container ) {
	Element	last_elt;
	bool	odd(false);

	if (container.size() <= 1)
		return container;
	if (container.size() % 2) {
		odd = true;
		last_elt = container.back();
	}

	std::deque<Element>	new_container;
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

	std::deque<PendElement>	losers_lst = ExtractLosers(new_container);
	if (!losers_lst.empty())
		new_container.insert(new_container.begin(), losers_lst[0].loser);
	
	size_t	Jnm1(3);
	size_t	Jnm2(1);
	size_t	last_insert(0);	
	while (last_insert + 1 < losers_lst.size()) {
		size_t	upper_bound = Jnm1 - 1;
		if (upper_bound >= losers_lst.size())
			upper_bound = losers_lst.size() - 1;
		
		for (size_t	idx = upper_bound; idx > last_insert; --idx)
			Dichotomie(new_container, DichotomieIndex(new_container, losers_lst[idx].winner_value), losers_lst[idx].loser);

		last_insert = upper_bound;
		size_t	Jn = 2 * Jnm2 + Jnm1;
		Jnm2 = Jnm1;
		Jnm1 = Jn;
	}

	if (odd == true)
		Dichotomie(new_container, new_container.size() - 1, last_elt);
	return new_container;
}

void	Pmerge::Sort() {
	struct timeval	start, end;

	std::cout << "Before: ";
	DisplayContainer();
	
	gettimeofday(&start, NULL);
	vect_ = FordJohnson(vect_);
	gettimeofday(&end, NULL);
	
	std::cout << "After:  ";
	DisplayContainer();

	double	time_diff = (static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec)) / 1000000.0;

	std::cout << "Time to process a range of "<< vect_.size() <<  " elements with std::vector : " << std::fixed << std::setprecision(6) << time_diff << " s\n";

	gettimeofday(&start, NULL);
	deque_ = FordJohnson(deque_);
	gettimeofday(&end, NULL);

	time_diff = (static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec)) / 1000000.0;

	std::cout << "Time to process a range of " << deque_.size() << " elements with std::deque  : " << std::fixed << std::setprecision(6) << time_diff << " s\n";
}
