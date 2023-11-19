/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 18:04:49 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
