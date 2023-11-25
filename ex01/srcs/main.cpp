/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/22 21:48:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Why use this container?
// std::stack is a container adapter that gives the programmer 
// the functionality of a stack - specifically, a LIFO (last-in, first-out)
// data structure.

// The class template acts as a wrapper to the underlying container -
// only a specific set of functions is provided.

// The stack pushes and pops the element from the back of the underlying container,
// known as the top of the stack.

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
		return 1;
	}
	else
	{
		RPN calculator;
		try 
		{
			double result = calculator.evaluate(argv[1]);
			std::cout << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}		
	}
	return 0;
}
