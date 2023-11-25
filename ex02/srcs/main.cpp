/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/25 19:38:17 by tpereira         ###   ########.fr       */
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


 // #include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

void insertionSortVector(std::vector<int>& sequence, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > left && key < sequence[j - 1]) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

void mergeVector(std::vector<int>& sequence, size_t left, size_t middle, size_t right) {
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (size_t i = 0; i < n1; ++i)
        L[i] = sequence[left + i];
    for (size_t j = 0; j < n2; ++j)
        R[j] = sequence[middle + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            sequence[k] = L[i];
            ++i;
        } else {
            sequence[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        sequence[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        sequence[k] = R[j];
        ++j;
        ++k;
    }
}

void fordJohnsonVector(std::vector<int>& sequence, size_t left, size_t right) {
    const size_t threshold = 100;

    if (right - left + 1 <= threshold) {
        insertionSortVector(sequence, left, right);
    } else {
        size_t middle = left + (right - left) / 2;

        fordJohnsonVector(sequence, left, middle);
        fordJohnsonVector(sequence, middle + 1, right);

        mergeVector(sequence, left, middle, right);
    }
}

void insertionSortDeque(std::deque<int>& sequence, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > left && key < sequence[j - 1]) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

void mergeDeque(std::deque<int>& sequence, size_t left, size_t middle, size_t right) {
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    std::deque<int> L(sequence.begin() + left, sequence.begin() + left + n1);
    std::deque<int> R(sequence.begin() + middle + 1, sequence.begin() + middle + 1 + n2);

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            sequence[k] = L[i];
            ++i;
        } else {
            sequence[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        sequence[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        sequence[k] = R[j];
        ++j;
        ++k;
    }
}

void fordJohnsonDeque(std::deque<int>& sequence, size_t left, size_t right) {
    const size_t threshold = 100;

    if (right - left + 1 <= threshold) {
        insertionSortDeque(sequence, left, right);
    } else {
        size_t middle = left + (right - left) / 2;

        fordJohnsonDeque(sequence, left, middle);
        fordJohnsonDeque(sequence, middle + 1, right);

        mergeDeque(sequence, left, middle, right);
    }
}


int main(int argc, char **argv)
{
	clock_t start, end;
	clock_t start2, end2;
    // Test with std::vector
    std::vector<int> vectorSequence;
	for (int i = 1; i < argc; ++i)
	{
		vectorSequence.push_back(std::atoi(argv[i]));
	}

    std::cout << "Original Vector: ";
    // for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); ++it)
	// {
    // 	std::cout << *it << " ";
	// }
    std::cout << std::endl;
	start = clock();
    fordJohnsonVector(vectorSequence, 0, vectorSequence.size() - 1);
	end = clock();
    std::cout << "Sorted Vector in " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    // for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); ++it)
	// {
    //     std::cout <<  *it  << " ";
    // }
    std::cout << std::endl << std::endl;

    // Test with std::deque
	std::deque<int> dequeSequence;
	for (int i = 1; i < argc; ++i)
	{
		dequeSequence.push_back(std::atoi(argv[i]));
	}

    std::cout << "Original Deque: ";
    // for (std::deque<int>::iterator it = dequeSequence.begin(); it != dequeSequence.end(); ++it)
	// {
    // 	std::cout << *it << " ";
	// }

    std::cout << std::endl;
	start2 = clock();
	fordJohnsonDeque(dequeSequence, 0, dequeSequence.size() - 1);
	end2 = clock();

    std::cout << "Sorted Deque in " << (double)(end2 - start2) / CLOCKS_PER_SEC << " seconds" << std::endl;
    // for (std::deque<int>::iterator it = dequeSequence.begin(); it != dequeSequence.end(); ++it)
	// {
    // 	std::cout << *it << " ";
	// }
    std::cout << std::endl;

    return 0;
}



// C++ program to implement Ford-Johnson algorithm
// It will be used to sort a vector, a deque and a list
// taking in consideration the constraints of each container
// and the time it takes to sort each one of them

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		std::cerr << "Error" << std::endl;
// 		return 1;
// 	}

// 	PmergeMe pmerge(argv[1]);
// 	pmerge.sortVector();
// 	pmerge.sortDeque();
// 	pmerge.sortList();


// 	return 0;
// }
