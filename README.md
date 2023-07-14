# Sorts-Library
The Sorts library provides various sorting algorithms for sorting arrays of integer values. It also includes binary search and merge sort functions.

# Directory Structure
The relevant files for the Sorts library are located in the current directory:

* **sorts.h:** Header file defining the interface and function prototypes for the sorting algorithms.
* **sorts.c:** Source file containing the implementation of the sorting algorithms.

# Available Sorting Algorithms
The Sorts library provides the following sorting algorithms:

* **Bubble Sort:** BubbleSort(int *array, size_t length)
* **Selection Sort:** SelectionSort(int *array, size_t length)
* **Insertion Sort:** InsertionSort(int *array, size_t length)
* **Count Sort:** CountSort(int *array, size_t length)
* **Radix Sort:** RadixSort(int *array, size_t length)
* **Merge Sort:** MergeSort(int *array, size_t length)
* **Quick Sort:** QuickSort(void *array, size_t length, size_t element_size, int (*cmp_func)(const void *left, const void *right))

# Binary Search
The Sorts library also provides binary search functions:

* **Iterative Binary Search: BinarySearchIter(int *array, size_t length, int value)
* **Recursive Binary Search: BinarySearchRec(int *array, size_t length, int value)

# Usage
To use the Sorts library, follow these steps:

1. Include the sorts.h header file in your C program.
2. Link the sorts.c source file with your program.
3. Build and compile your program.

For example, to use the Sorts library:
```
#include <stdio.h>
#include "sorts.h"

int main() {
    // Your code using the Sorts library here

    return 0;
}
```

Compile the program using the Sorts source file:
```
gcc main.c sorts.c -o program
```

```
./program
```

# Contributing
Contributions to the Sorts library implementation are welcome. If you find any issues or want to improve the existing implementation, feel free to open a pull request.
