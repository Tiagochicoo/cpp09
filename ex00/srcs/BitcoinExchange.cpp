/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:56:37 by tpereira          #+#    #+#             */
/*   Updated: 2023/09/16 12:01:30 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

bool BitcoinExchange::parseDatabase(std::ifstream &file, std::map<std::string, double> &database)
{
	std::string line;
	// Skip first line
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		double value;
		std::istringstream iss(line);

		if (!(std::getline(iss,date, ',') >> value))
		{
			std::cout << "Error: Invalid format in bitcoin database file." << std::endl;
			return false;
		}
		database[date] = value;		
	}
	return true;
}

bool BitcoinExchange::parseInput(std::ifstream &file, std::map<std::string, double> &input) 
{
    std::string line;

	// Skip first line
	std::getline(file, line);
    while (std::getline(file, line)) 
	{
        std::string date;
        double value;

        // Find the position of the '|' character
        size_t separatorPos = line.find('|');

        if (separatorPos != std::string::npos)
		{
            // Extract date from the line
            date = line.substr(0, separatorPos);

            // Find the position of the first number after the '|'
            size_t valuePos = line.find_first_of("-0123456789", separatorPos);

            if (valuePos != std::string::npos) {
                // Extract numeric value from the line
                std::istringstream valueStream(line.substr(valuePos));
                if (!(valueStream >> value)) 
				{
                    std::cout << "Error: Invalid value format in the line." << std::endl;
                    return false;
                }

                // Add the date and value to the map
                input[date] = value;
            }
			else
				std::cout << "Error: No numeric value found in the line." << std::endl;
        } 
		else 
            std::cout << "Error: No '|' separator found in the line." << std::endl;
    }
    
    return true;
}


std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
