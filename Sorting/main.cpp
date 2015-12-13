//
//  main.cpp
//  Sorting
//
//  Created by Alexander Robau on 12/11/14.
//  Copyright (c) 2014 Robau. All rights reserved.
//

#include <iostream>
#include "sorting_algorithms.h"

int main(int argc, const char * argv[]) {
  int* array = new int[100];
  for (int i = 0; i < 100; ++i) {
    array[i] = 100 - i;
  }
  sort::merge_sort(array, array + 100);
  for (int i = 0; i < 100; ++i) {
    std::cout << array[i] << " ";
  }
}
