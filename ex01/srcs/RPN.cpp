/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:17 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 18:17:30 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}


std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

double RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::stack<double> stack;

	while (!iss.eof())
	{
		std::string token;
		iss >> token;

		if (isNumber(token))
		{
			char *endptr;
			if (strtod(token.c_str(), &endptr) > 10)
				throw std::invalid_argument("Numbers used in operation are bigger than 10.");
			else
				stack.push(std::strtod(token.c_str(), &endptr));
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid Expression: insufficient operands for operator.");

			double operand2 = stack.top();
			stack.pop();
			double operand1 = stack.top();
			stack.pop();
			double result = applyOperator(operand1, operand2, token);
			stack.push(result);
		}
		else
			throw std::invalid_argument("Invalid token expression.");
	}

	if (stack.size() != 1)
	{
		throw std::invalid_argument("Invalid Expression: too many operands.");
	}

    return stack.top();
}

bool RPN::isNumber(const std::string &token)
{
    char *endptr;
    strtod(token.c_str(), &endptr);

    // Check for conversion error
    if (*endptr != '\0' || errno == ERANGE)
    {
        errno = 0; // Reset errno
        return false;
    }

    return true;
}

bool RPN::isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isSpace(const std::string &token)
{
	return token == " ";
}

double RPN::applyOperator(double operand1, double operand2, const std::string &token)
{
    if (token == "+")
		return operand1 + operand2;
	else if (token == "-")
		return operand1 - operand2;
	else if (token == "*")
		return operand1 * operand2;
	else if (token == "/")
	{
		if (operand2 == 0)
			throw std::invalid_argument("Division by 0.");
		return operand1 / operand2;
	}
	else
		throw std::invalid_argument("Unkown operator");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */