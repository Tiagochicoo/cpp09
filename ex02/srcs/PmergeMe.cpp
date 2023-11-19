/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:25:14 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 19:43:08 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(const char *numbers)
{
	char *token = std::strtok(const_cast<char*>(numbers), " ");
	while (token != NULL)
	{
		_vector.push_back(std::atoi(token));
		_list.push_back(std::atoi(token));
		token = std::strtok(NULL, " ");
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::displayNumbers(std::string &when) const
{
	std::cout << when;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) 
	{
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::measureTime()
{
	// Measure time for std::vector
    clock_t vectorStart = clock();
    std::sort(_vector.begin(), _vector.end());
    clock_t vectorEnd = clock();
    double vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1e6;

    // Copy list for sorting since sort is a non-const member function
    std::list<int> tempList = _list;

    // Measure time for std::list
    clock_t listStart = clock();
    tempList.sort();
    clock_t listEnd = clock();
    double listTime = static_cast<double>(listEnd - listStart) / CLOCKS_PER_SEC * 1e6;

	// Display numbers after sorting them
	std::string after = "After: ";
	displayNumbers(after);

    // Display time measurements
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << listTime << " us" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */