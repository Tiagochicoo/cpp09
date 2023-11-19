/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:25:11 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 19:39:55 by tpereira         ###   ########.fr       */
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