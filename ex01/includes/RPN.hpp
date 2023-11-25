/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:00 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/25 19:11:31 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cerrno>

class RPN
{
private:
	std::stack<int> _numbers;

	// Helper functions that are only called from within the class (evaluate())
	bool isNumber(const std::string &token);
	bool isOperator(const std::string &token);
	double applyOperator(double operand1, double operand2, const std::string &token);

public:
	RPN();
	RPN(RPN const &src);
	~RPN();

	RPN &operator=(RPN const &rhs);

	double evaluate(const std::string &expression);
	std::stack<int> getNumbers() const;
};

std::ostream &operator<<(std::ostream &o, RPN const &i);

#endif /* ************************************************************* RPN_H */
