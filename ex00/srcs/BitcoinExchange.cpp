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

bool isValidDate(std::string &date)
{
	std::string year;
	std::string month;
	std::string day;
	unsigned int y;
	unsigned int m;
	unsigned int d;

	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);

	std::istringstream iss_year(year);
	iss_year >> y;
	std::istringstream iss_month(month);
	iss_month >> m;
	std::istringstream iss_day(day);
	iss_day >> d;
	if (y < 2009)
		std::cout << "Error: BTC didn't exist as a currency that year (" << y << ")!" << std::endl;
	if (m == 0 || m > 12 || d == 0 || d > 31 || (m == 2 && d > 29))
		std::cout << "Error: bad input => " << date << std::endl;

	return true;
}

bool isValidNumber(double &number)
{
	if (number > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	else if (number < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

bool isValidFloat(const std::string &number)
{
	char *endptr;
	strtod(number.c_str(), &endptr);

	return (*endptr == '\0' || *endptr == '\n') && errno != ERANGE;
}

void printInput(std::map<std::string, double> &input)
{
	
}

bool BitcoinExchange::parseInput(std::ifstream &file, std::map<std::string, double> &input) 
{
    std::string line;

	// Skip first line
	std::getline(file, line);
    while (std::getline(file, line)) 
	{
        std::string date;
        std::string number;
        double value;

        // Find the position of the '|' character
        size_t separatorPos = line.find('|');

        if (separatorPos != std::string::npos)
		{
            // Extract date from the line
            date = line.substr(0, separatorPos);

			if (isValidDate(date))
			{
				// Find the position of the first number after the '|'
				size_t valuePos = line.find_first_of("-0123456789", separatorPos);

				if (valuePos != std::string::npos)
				{
					std::string numericSubstring = line.substr(valuePos);
					size_t lastNumericPos = numericSubstring.find_last_of("0123456789");

                    // Extract the substring containing only numeric characters
                    std::istringstream valueStream(numericSubstring.substr(0, lastNumericPos + 1));
					if (!(valueStream >> value))
					{
						std::cout << "Error: Invalid value format in the line." << std::endl;
					}
					else if (isValidNumber(value) && isValidFloat(line.substr(valuePos)))
					{
						// Add the date and value to the map
						input[date] = value;
					}
				}
				else
					std::cout << "Error: No numeric value found in the line." << std::endl;
			}
        } 
		else 
            std::cout << "Error: No '|' separator found in the line." << std::endl;
    }
	printInput(input);
    
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
