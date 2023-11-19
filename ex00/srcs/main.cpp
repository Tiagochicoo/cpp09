/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:20:18 by tpereira          #+#    #+#             */
/*   Updated: 2023/09/16 12:02:16 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <database>.csv" << std::endl;
		return 1;
	}
	else
	{
		BitcoinExchange exchange;
		std::ifstream inputFile(argv[1]);
		if (inputFile.is_open())
		{
			std::map<std::string, double> inputDatabase;
			if (exchange.parseInput(inputFile, inputDatabase))
				return 0;
		}
		else
		{
			std::cout << "Error: could not open file." << std::endl;
			return 1;
		}
	}
	return 0;
}
