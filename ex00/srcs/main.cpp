/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:20:18 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/22 19:49:58 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Why use this container?
// std::map is an associative container that stores elements in a mapped fashion.
// Each element has a key value and a mapped value. No two mapped values can have
// same key values.

// The key values are used to sort and uniquely identify the elements, while the
// mapped values store the content associated to this key.

// The mapped value can be accessed directly by their corresponding key using the
// bracket operator ([]).

// std::map containers are generally slower than unordered_map containers to
// access individual elements by their key, but they allow the direct iteration
// on subsets based on their order.

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
