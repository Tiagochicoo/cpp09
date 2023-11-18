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

	std::ifstream btcCSV("data.csv");
	if (btcCSV.is_open())
	{
		BitcoinExchange bitcoinExchange;
		std::map<std::string, double> bitcoinDatabase;
		std::cout << "Loading database..." << std::endl;
		if (bitcoinExchange.parseDatabase(btcCSV, bitcoinDatabase))
		{
			std::cout << "Database parsed Successfully!" << std::endl;
			std::ifstream inputFile(argv[1]);
			if (inputFile.is_open())
			{
				std::map<std::string, double> inputDatabase;
				std::cout << "Loading input..." << std::endl;
				if (bitcoinExchange.parseInput(inputFile, inputDatabase))
					return 0;
			}
			else
			{
				std::cout << "Error: Unable to open input file." << std::endl;
				return 1;
			}
		}
		else
		{
			std::cout << "Error: Unable to open database file." << std::endl;
			return 1;
		}
	}
	else
	{
		std::cout << "Error: Unable to open bitcoin database file." << std::endl;
		return 1;
	}
	return 0;
}
