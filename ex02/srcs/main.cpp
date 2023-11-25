/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/25 18:27:36 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here are a few container types you can consider testing with:

/* std::vector: This container provides contiguous memory storage,
which can lead to better cache locality. It's suitable for scenarios
where you often iterate over the elements sequentially.

std::list: This container uses a doubly-linked list, which can be beneficial
for insertion and deletion operations in the middle of the container. However,
it may have poorer cache locality compared to std::vector for sequential access.

std::deque: This container is a double-ended queue, providing fast insertion
and deletion at both ends. It consists of multiple fixed-size blocks of memory,
which can offer better cache locality than std::list but may not be as
contiguous as std::vector.

std::array: This container has a fixed size determined at compile time.
It provides contiguous memory storage like std::vector but without dynamic
resizing.
 */
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pmerge(argv[1]);
	std::string before = "Before: ";
	// pmerge.displayNumbers(before);
	pmerge.measureTime();

	return 0;
}
