/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:25:11 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/20 07:21:53 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::list<int>   _list;
		
		void vectorFordJohnson(std::vector<int> _vector);
		void vectorFordJohnson(std::list<int> _list);
		
		template <typename Container>
		void fordJohnson(Container &sequence)
		{
			// Separate integers in half
			typename Container::iterator it;
			std::vector<int> topHalf;
			std::vector<int> bottomHalf;
			int size = sequence.size();

			for (it = sequence.begin(); it != sequence.end(); ++it) 
			{
				if (*it >= size) 
					topHalf.push_back(*it);
				else
					bottomHalf.push_back(-(*it));
			}

			// Sort top half of integers in ascending order
			std::sort(topHalf.begin(), topHalf.end());

			// Sort bottom half of integers in descending order
			std::sort(bottomHalf.rbegin(), bottomHalf.rend());

			// Merge the sorted topHalf and bottomHalf integers
			sequence.clear();
			sequence.insert(sequence.end(), topHalf.begin(), topHalf.end());

			for (typename std::vector<int>::iterator it = bottomHalf.begin(); it != bottomHalf.end(); ++it) 
			{
				sequence.push_back(-(*it));
			}
		}


	public:

		PmergeMe();
		PmergeMe(const char *numbers);
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		void displayNumbers(std::string &when) const;
		void measureTime();


};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */
