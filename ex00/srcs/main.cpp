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

#include <iostream>
#include <list>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./btc <database>.csv" << std::endl;
		return 1;
	}
	else
	{
		std::string filename(argv[1]);
		if (filename.find(".csv") == std::string::npos)
		{
			std::cout << "Usage: ./btc <database>.csv" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Loading database..." << std::endl;
			std::list<BitcoinExchange> database;
		}
	}
	return 0;
}
