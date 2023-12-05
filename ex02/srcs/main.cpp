/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/25 19:42:30 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
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

    std::vector<int> L(sequence.begin() + left, sequence.begin() + left + n1);
    std::vector<int> R(sequence.begin() + middle + 1, sequence.begin() + middle + 1 + n2);

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

void insertionSortDeque(std::deque<int>& sequence, size_t left, size_t right) {
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

int main(int argc, char** argv) {
    clock_t start, end;
    clock_t start2, end2;
    int i = 0;

    // Test with std::vector
    std::vector<int> vectorSequence;
    for (int i = 1; i < argc; ++i) {
        vectorSequence.push_back(std::atoi(argv[i]));
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); ++it)
	{
    	if (i++ == 10)
            std::cout << "[...]";
        else if (i > 10)
            break;
        else
    	    std::cout << *it << " ";
	}
    std::cout << std::endl;
    start = clock();
    fordJohnsonVector(vectorSequence, 0, vectorSequence.size() - 1);
    end = clock();
    
    i = 0;
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); ++it)
	{
        if (i++ == 10)
            std::cout << "[...]";
        else if (i > 10)
            break;
        else
    	    std::cout << *it << " ";
    }
    std::cout << std::endl;

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    time_taken /= 0.000001;
    std::cout << std::fixed  << std::setprecision(5) << "Time to process a range of " << vectorSequence.size() << " elements with std::vector : " << time_taken << std::setprecision(10) << " us" << std::endl;

    // Test with std::deque
    std::deque<int> dequeSequence;
    for (int i = 1; i < argc; ++i) {
        dequeSequence.push_back(std::atoi(argv[i]));
    }

    i = 0;
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = dequeSequence.begin(); it != dequeSequence.end(); ++it)
	{
    	if (i++ == 10)
            std::cout << "[...]";
        else if (i > 10)
            break;
        else
    	    std::cout << *it << " ";
	}
    std::cout << std::endl;
    start2 = clock();
    fordJohnsonDeque(dequeSequence, 0, dequeSequence.size() - 1);
    end2 = clock();

    i = 0;
    std::cout << "After: ";
    for (std::deque<int>::iterator it = dequeSequence.begin(); it != dequeSequence.end(); ++it)
	{
        if (i++ == 10)
            std::cout << "[...]";
        else if (i > 10)
            break;
        else
    	    std::cout << *it << " ";
	}
    std::cout << std::endl;

    time_taken = (double)(end2 - start2) / CLOCKS_PER_SEC;
    time_taken /= 0.000001;
    std::cout << std::fixed  << std::setprecision(5) << "Time to process a range of " << dequeSequence.size() << " elements with std::deque : " << time_taken << " us" << std::endl;

    return 0;
}
