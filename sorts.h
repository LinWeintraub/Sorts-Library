#ifndef __SORTS__
#define __SORTS__

#include <stddef.h>

void BubbleSort(int *array, size_t length);

void SelectionSort(int *array, size_t length);

void InsertionSort(int *array, size_t length);

void CountSort(int *array, size_t length);

void RadixSort(int *array, size_t length);

/*----------------------------------------------------------------------------
Params: array - pointer to a sorted array of integer values.
        length - number of items in array.
        value - integer which we are looking for in array.
Return: The index of value in array.
        If it is not in array, -1 is returned.
Complexity: O(logn) worst case, O(1) best case. */

long BinarySearchIter(int *array, size_t length, int value);
long BinarySearchRec(int *array, size_t length, int value);

/*----------------------------------------------------------------------------
Params: array - pointer to an array of integer values.
        length - number of items in array.
Return: ?
Complexity: O(logn) */

int MergeSort(int *array, size_t length);

/*----------------------------------------------------------------------------
Params: array - pointer to an array of integer values.
        length - number of items in array.
Return: -
Complexity: O(n) worst case, O(logn) average case. */

void QuickSort(void *array, 
               size_t length, 
               size_t element_size, 
               int (*cmp_func)(const void *left, const void *right));

#endif /* __SORTS__ */
