/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:25:11 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 23:17:48 by tpereira         ###   ########.fr       */
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
			// Separate positive and negative integers
			typename Container::iterator it;
			std::vector<int> positive;
			std::vector<int> negative;

			for (it = sequence.begin(); it != sequence.end(); ++it) {
				if (*it >= 0) {
					positive.push_back(*it);
				} else {
					negative.push_back(-(*it));
				}
			}

			// Sort positive integers in ascending order
			std::sort(positive.begin(), positive.end());

			// Sort negative integers in descending order
			std::sort(negative.rbegin(), negative.rend());

			// Merge the sorted positive and negative integers
			sequence.clear();
			sequence.insert(sequence.end(), positive.begin(), positive.end());

			for (typename std::vector<int>::iterator it = negative.begin(); it != negative.end(); ++it) {
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