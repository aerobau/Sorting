//
//  sorting_algorithms.h
//  Sorting
//
//  Created by Alexander Robau on 12/11/14.
//  Copyright (c) 2014 Robau. All rights reserved.
//

#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

#include <cstddef>
#include <ctime>

namespace sort {


template<typename T>
void swap(T& first, T& second) {
    T temp = std::move(first);
    first = std::move(second);
    second = std::move(temp);
}

template<typename T>
void merge(T* start_1, T* end_1, T* start_2, T* end_2,
           bool (*less_than)(T first, T second) = nullptr) {
    // Creates iterators to iterate over the list, and allocates a side array called result for the
    // resulting value.
    T* iter_1 = start_1;
    T* iter_2 = start_2;
    T* aux_iter = start_2;
  
    // When values exist in both of the arrays to be merged, do a check for less than, and assign
    // the lower value to the auxillary array and increment both pointers
    while (iter_2 != end_2 || aux_iter != end_2) {
        if (aux_iter != iter_2) {
            // Aux contains items
            if (less_than) {
                if (less_than(*iter_1, *iter_2)) {
                    if (less_than(*aux_iter, *iter_1)) {
                        // Aux has the min value, swap with iter_1, increment aux and iter_1
                        swap(*iter_1++, *aux_iter++);
                    } else {
                        // iter_1 has the min value, simply increment iter_1
                        ++iter_1;
                    }
                } else {
                    if (less_than(*aux_iter, *iter_2)) {
                        // Aux has the min value, swap with iter_1, increment aux and iter_1
                        swap(*iter_1++, *aux_iter++);
                    } else {
                        // iter_2 has the min value, swap with iter_1 and increment both
                        swap(*iter_1++, *iter_2++);
                    }
                }
            } else {
                if (*iter_1 < *iter_2) {
                    if (*aux_iter < *iter_1) {
                        // Aux has the min value, swap with iter_1, increment aux and iter_1
                        swap(*iter_1++, *aux_iter++);
                    } else {
                        // iter_1 has the min value, simply increment iter_1
                        ++iter_1;
                    }
                } else {
                    if (*aux_iter < *iter_2) {
                        // Aux has the min value, swap with iter_1, increment aux and iter_1
                        swap(*iter_1++, *aux_iter++);
                    } else {
                        // iter_2 has the min value, swap with iter_1 and increment both
                        swap(*iter_1++, *iter_2++);
                    }
                }
            }
        } else if (less_than ? less_than(*iter_1, *iter_2) : *iter_1 < *iter_2) {
            // iter_1 simply needs to be incremeted since aux is empty and iter_2 does not have a
            // value less than iter_1's
            ++iter_1;
        } else {
            // iter_2 needs to be swapped with iter_1 and both incremented, essentially adding an
            // item to the aux and placing an item in the correct place
            swap(*iter_1++, *iter_2++);
        }
        
        if (iter_1 == aux_iter) {
            aux_iter = iter_2;
        }
        
        if (iter_2 == end_2) {
            iter_2 = aux_iter;
        }
    }
}
  
template<typename T>
void merge_sort(T* start, T* end,
                bool (*less_than)(T first, T second) = nullptr) {
  int size = (int)(end - start);
  if (size == 1) {
    return;
  } else {
    T* mid = &start[size / 2];
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, mid, mid, end, less_than);
  }
}
  
template<typename T>
T* partition(T* start, T* end,
               bool (*less_than)(T first, T second) = NULL) {
  int size = (int)(end - start);
  int pivot = rand() % size;
  swap(start[0], start[pivot]);
  T* left = start + 1;
  T* right = end - 1;
  while (left < right) {
    if (*left > *start) {
      swap(*left, *right);
      --right;
    } else if (*right < *start) {
      swap(*left, *right);
      ++left;
    } else {
      ++left;
      --right;
    }
  }
  while (*++right < *start && right < end) {}
  while (*--right > *start && right > start) {}
  swap(start[0], *right);
  return right;
}

template<typename T>
void quick_sort(T* start, T* end,
                bool (*less_than)(T first, T second) = NULL) {
  int size = (int)(end - start);
  if (size == 2) {
    if (*start > *(start + 1)) {
      swap(*start, *(start + 1));
    }
  }
  else  if ((int)(end - start) > 1) {
    std::srand((int)time(0));
    T* pivot = partition(start, end, less_than);
    if ((int)(pivot - start) == 0) {
      ++pivot;
    }
    quick_sort(start, pivot);
    quick_sort(pivot, end);
  }
}
  
}

#endif // SORTING_ALGORITHMS_H_
