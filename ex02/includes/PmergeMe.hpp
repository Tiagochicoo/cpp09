/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:25:11 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/25 18:27:19 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::list<int> _list;

	// void vectorFordJohnson(std::vector<int> _vector);
	// void vectorFordJohnson(std::list<int> _list);

	template <typename Container>
	void fordJohnson(Container &sequence)
	{
		// Separate integers in half
		typename Container::iterator it;
		Container topHalf;
		Container bottomHalf;
		int size = sequence.size();

		for (it = sequence.begin(); it != sequence.end(); ++it)
		{
			if (*it >= size)
			{
				topHalf.push_back(*it);
			}
			else
			{
				bottomHalf.push_back(-(*it));
			}
		}

		// Sort top half of integers in ascending order
		if (std::is_same_v<Container, std::vector<int>>::value)
		{
			std::sort(topHalf.begin(), topHalf.end());
		}
		else if (std::is_same_v<Container, std::list<int>>::value)
		{
			topHalf.sort();
		}

		// Sort bottom half of integers in descending order
		if (std::is_same_v<Container, std::vector<int>>::value)
		{
			std::sort(bottomHalf.rbegin(), bottomHalf.rend());
		}
		else if (std::is_same_v<Container, std::list<int>>::value)
		{
			bottomHalf.sort(std::greater<>{});
		}

		// Merge the sorted topHalf and bottomHalf integers
		sequence.clear();
		sequence.insert(sequence.end(), topHalf.begin(), topHalf.end());

		for (typename Container::iterator it = bottomHalf.begin();
			 it != bottomHalf.end(); ++it)
		{
			sequence.push_back(-(*it));
		}
	}

public:
	PmergeMe();
	PmergeMe(const char *numbers);
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	void displayNumbers(std::string &when) const;
	void measureTime();
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif /* ******************************************************** PMERGEME_H \
		*/
