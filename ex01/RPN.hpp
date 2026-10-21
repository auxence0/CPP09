/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:00:24 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/21 15:17:25 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>
# include <limits>
# include <list>

class	RPN {
	public:
		RPN( const std::string& arg );
		RPN( const RPN& obj );
		RPN&	operator=( const RPN& rhs );
		~RPN();

		void	calc_res();
	private:
		RPN();
		std::stack<int, std::list<int> >	s_;
		std::string		str_;
		bool	do_op( char op );
};

#endif