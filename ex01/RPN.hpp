/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:00:24 by asauvage          #+#    #+#             */
/*   Updated: 2026/10/05 16:38:48 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

class	RPN {
	public:
		RPN( const std::string& arg );
		RPN( const RPN& obj );
		RPN&	operator=( const RPN& rhs );
		~RPN();

	private:
		RPN();
		std::stack<int>	s;
};

#endif