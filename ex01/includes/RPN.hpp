/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:00 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/20 07:20:19 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>
# include <cstdlib>
# include <cerrno>

class RPN
{
	private:
		std::stack<int> numbers;

		bool isNumber(const std::string &token);
		bool isOperator(const std::string &token);
		bool isSpace(const std::string &token);
		double applyOperator(double operand1, double operand2, const std::string &token);

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		double evaluate(const std::string &expression);


};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */
