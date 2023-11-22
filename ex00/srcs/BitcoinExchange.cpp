/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:56:37 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/22 19:47:32 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream btcCSV("data.csv");
	if (btcCSV.is_open())
	{
		if (parseDatabase(btcCSV, _bitcoinDatabase))
		{
			std::cout << "Database parsed Successfully!" << std::endl;
		}
	}
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
	if ( this != &rhs )
	{
		_bitcoinDatabase = rhs.getBitcoinDatabase();
		inputDatabase = rhs.getInputDatabase();
	}
	return *this;
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
		database.insert(std::pair<std::string, double>(date, value));
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
	{
		std::cout << "Error: BTC didn't exist as a currency that year (" << y << ")!" << std::endl;
		return false;
	}
	if (m == 0 || m > 12 || d == 0 || d > 31 || (m == 2 && d > 29))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
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

void BitcoinExchange::printOutput(std::map<std::string, double>& line)
{
	// const_reverse_iterator because I don't need to change the iterator
    std::map<std::string, double>::const_reverse_iterator it = line.rbegin();

    if (it != line.rend())
    {
        const std::string &inputDate = it->first;
        double inputAmount = it->second;

        // Find the closest date in _bitcoinDatabase
        std::map<std::string, double>::const_iterator closestBitcoinIt = _bitcoinDatabase.lower_bound(inputDate);

        // If lower_bound returns the beginning of the map, use the first element
        if (closestBitcoinIt == _bitcoinDatabase.begin())
            closestBitcoinIt = _bitcoinDatabase.begin();
        // If lower_bound returns the end of the map, use the last element
        else if (closestBitcoinIt == _bitcoinDatabase.end())
            --closestBitcoinIt;
        // If not exactly equal, move to the previous element
        else if (closestBitcoinIt->first != inputDate)
            --closestBitcoinIt;

        double bitcoinRate = closestBitcoinIt->second;

		// Perform the calculation with long double for higher precision
		long double calculatedAmount = static_cast<long double>(inputAmount) * static_cast<long double>(bitcoinRate);

		// Set the precision for output
		std::cout << std::fixed << std::setprecision(2);

		// Print the result
		std::cout << inputDate << " => " << inputAmount << " => " << bitcoinRate << " => " << calculatedAmount << std::endl;
		}
}

bool BitcoinExchange::parseInput(std::ifstream &file, std::map<std::string, double> &input) 
{
    std::string line;

    // Skip first line
    if (!(std::getline(file, line)))
		return false;
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

            if (isValidDate(date))
            {
                // Find the position of the first number after the '|'
                size_t valuePos = line.find_first_of("-0123456789", separatorPos);

                if (valuePos != std::string::npos)
                {
                    // Extract numeric value from the line
                    std::istringstream valueStream(line.substr(valuePos));
                    if (!(valueStream >> value))
                    {
                        std::cout << "Error: Invalid value format in the line." << std::endl;
                    }
                    else if (isValidNumber(value) && isValidFloat(line.substr(valuePos)))
                    {
                        // Add the date and value to the map
                        input[date] = value;
                        this->printOutput(input);
                    }
                }
                else
                    std::cout << "Error: No numeric value found in the line." << std::endl;
            }
        } 
        else 
            std::cout << "Error: No '|' separator found in the line." << std::endl;
    }
    return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::map<std::string, double> BitcoinExchange::getBitcoinDatabase() const
{
	return _bitcoinDatabase;
}

std::map<std::string, double> BitcoinExchange::getInputDatabase() const
{
	return inputDatabase;
}

/* ************************************************************************** */
