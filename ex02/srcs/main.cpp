#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

// Optimized insertion sort for std::vector
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

// Optimized merge for std::vector
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

// Optimized Ford-Johnson for std::vector
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

// Optimized insertion sort for std::deque
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

// Optimized merge for std::deque
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

// Optimized Ford-Johnson for std::deque
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

    // Test with std::vector
    std::vector<int> vectorSequence;
    for (int i = 1; i < argc; ++i) {
        vectorSequence.push_back(std::atoi(argv[i]));
    }

    std::cout << "Original Vector: ";
    std::cout << std::endl;
    start = clock();
    fordJohnsonVector(vectorSequence, 0, vectorSequence.size() - 1);
    end = clock();
    std::cout << "Sorted Vector in " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout << std::endl;

    // Test with std::deque
    std::deque<int> dequeSequence;
    for (int i = 1; i < argc; ++i) {
        dequeSequence.push_back(std::atoi(argv[i]));
    }

    std::cout << "Original Deque: ";
    std::cout << std::endl;
    start2 = clock();
    fordJohnsonDeque(dequeSequence, 0, dequeSequence.size() - 1);
    end2 = clock();

    std::cout << "Sorted Deque in " << (double)(end2 - start2) / CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout << std::endl;

    return 0;
}
