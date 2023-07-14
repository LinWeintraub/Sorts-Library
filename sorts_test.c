/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ *
 ~ Author        Lin Weintraub                                   ~
 * Version       2.0.0                                           *
 ~ Date          1/12/22                                         ~
 * Description   Sorts                                           *
 * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */
 
#include <stdio.h> /* printf */
#include <stdlib.h> /* rand */
#include <time.h> /* clock */
#include <string.h> /* strcmp */

#include "sorts.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define WHITE "\033[0m"

#define TEST(name, actual, expected) \
    printf("%s: %s\n" , name, actual == expected ? GREEN"PASS"WHITE : RED"FAIL"WHITE)
#define TESTNOT(name, actual, expected) \
    printf("%s: %s\n" , name, actual != expected ? GREEN"PASS"WHITE : RED"FAIL"WHITE)


void TestBubbleSort(void);
void TestSelectionSort(void);
void TestInsertionSort(void);
void TestQSort(void);
void TestCountSort(void);
void TestRadixSort(void);
void TestBinarySearch(void);
void TestBinarySearchRec(void);
void TestMergeSort(void);
void TestQuickSort(void);

void PrintArray(int *arr, int length);
int Cmp(const void *a, const void *b);

int main(void)
{
	clock_t my_clock1;
	clock_t my_clock2;
	clock_t my_clock3;
	clock_t my_clock4;
	clock_t my_clock5;
	clock_t my_clock6;
	clock_t my_clock7;
	clock_t my_clock8;
	clock_t my_clock9;
	clock_t my_clock10;


	TestBubbleSort();
	my_clock1 = clock();
	printf("TestBubbleSort time: %ld\n", (long int)my_clock1);
    printf("\n");
    
	TestSelectionSort();
	my_clock2 = clock();
	printf("TestSelectionSort time: %ld\n", (long int)(my_clock2 - my_clock1));
    printf("\n");
    
	TestInsertionSort();
	my_clock3 = clock();
	printf("TestInsertionSort time: %ld\n", (long int)(my_clock3 - my_clock2));
	
	printf("\n");    
	
	TestQSort();
	my_clock4 = clock();
	printf("TestQSort time: %ld\n", (long int)(my_clock4 - my_clock3));
	
	printf("\n");    
	
	TestCountSort();
	my_clock5 = clock();
	printf("TestCountSort time: %ld\n", (long int)(my_clock5 - my_clock4));
	
	printf("\n");    
	
	TestRadixSort();
	my_clock6 = clock();
	printf("TestRadixSort time: %ld\n", (long int)(my_clock6 - my_clock5));

	printf("\n");    
	
	TestBinarySearch();
	my_clock7 = clock();
	printf("TestBinarySearch time: %ld\n", (long int)(my_clock7 - my_clock6));

	printf("\n");    
	
	TestBinarySearchRec();
	my_clock8 = clock();
	printf("TestBinarySearchRec time: %ld\n", (long int)(my_clock8 - my_clock7));

	printf("\n");    

	TestMergeSort();
	my_clock9 = clock();
	printf("TestMergeSort time: %ld\n", (long int)(my_clock9 - my_clock8));

	printf("\n");    

	TestQuickSort();
	my_clock10 = clock();
	printf("TestQuickSort time: %ld\n", (long int)(my_clock10 - my_clock9));

	return 0;
}
void TestBubbleSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000];
	int test_status = 0; 
		
	printf("TestBubbleSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestBubbleSort simple test - After: ");
	BubbleSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	BubbleSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestBubbleSort 5K test: ");
	
	TEST("TestBubbleSort", test_status, 0);
}

void TestSelectionSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000];
	int test_status = 0; 
	
	printf("TestSelectionSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestSelectionSort simple test - After: ");
	SelectionSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	SelectionSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("SelectionSortSort 5K test: ");
	
	TEST("SelectionSortSort", test_status, 0);
}

void TestInsertionSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000] = {0};
	int test_status = 0; 
	
	printf("TestInsertionSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestInsertionSort simple test - After: ");
	InsertionSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	InsertionSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestInsertionSort 5K test: ");
	
	TEST("TestInsertionSort", test_status, 0);
}

void TestQSort(void)
{
	int i = 0;
	int random[5000] = {0};
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
   	qsort(random, 5000, sizeof(int), Cmp);
}

void TestCountSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000] = {0};
	int test_status = 0; 
	
	printf("TestCountSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestCountSort simple test - After: ");
	CountSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	CountSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestCountSort 5K test: ");
	
	TEST("TestCountSort", test_status, 0);
}

void TestRadixSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, 5, 3, 1 , 2};
	int random[5000] = {0};
	int test_status = 0; 
	
	printf("TestRadixSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestRadixSort simple test - After: ");
	RadixSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % (9999999 - 1000000 + 1) + 1000000;
	}
	
	RadixSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestRadixSort 5K test: ");
	
	TEST("TestRadixSort", test_status, 0);
}

void TestBinarySearch(void)
{
	int i = 0;
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int big_array[5000] = {0};
	long result = 0;
	
	result = BinarySearchIter(arr, 6, 1);
	TEST("TestBinarySearch", result, 0);

	result = BinarySearchIter(arr, 6, 4);
	TEST("TestBinarySearch", result, 3);
	
	for (i = 0; i < 5000; ++i)
	{
		big_array[i] = i;
	}
	
	result = BinarySearchIter(big_array, 5000, 561);
	TEST("TestBinarySearch", result, 561);

	result = BinarySearchIter(big_array, 5000, 8000);
	TEST("TestBinarySearch", result, -1);
}

void TestBinarySearchRec(void)
{
	int i = 0;
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int big_array[5000] = {0};
	long result = 0;
	
	result = BinarySearchRec(arr, 6, 1);
	TEST("TestBinarySearchRec", result, 0);

	result = BinarySearchRec(arr, 6, 4);
	TEST("TestBinarySearchRec", result, 3);
	
	for (i = 0; i < 5000; ++i)
	{
		big_array[i] = i;
	}
	
	result = BinarySearchRec(big_array, 5000, 561);
	TEST("TestBinarySearchRec", result, 561);

	result = BinarySearchRec(big_array, 5000, 8000);
	TEST("TestBinarySearchRec", result, -1);
}

void TestMergeSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000];
	int test_status = 0; 
		
	printf("TestMergeSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestMergeSort simple test - After: ");
	MergeSort(arr, 6);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	MergeSort(random, 5000);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestMergeSort 5K test: ");
	
	TEST("TestMergeSort", test_status, 0);
}

void PrintArray(int *arr, int length)
{
	int i = 0;
	
    for (i = 0; i < length; ++i)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int Cmp(const void *a, const void *b) 
{
   return (*(int*)a - *(int*)b);
}

void TestQuickSort(void)
{
	int i = 0;
	int arr[6] = {6 , 4, -5, 3, 1 , 2};
	int random[5000] = {0};
	int test_status = 0; 
	
	printf("TestQuickSort simple test - Before: ");
	PrintArray(arr, 6);
	
	printf("TestQuickSort simple test - After: ");
	QuickSort(arr, 6, 4, Cmp);
	PrintArray(arr, 6);
	
	for (i = 0; i < 5000; ++i)
	{
		random[i] = rand() % 1000;
	}
	
	QuickSort(random, 5000, 4, Cmp);
	
	for (i = 0; i < 5000 - 1; ++i)
	{
		if (random[i] > random[i + 1])
		{
			test_status = 1;
		}
	}
	
	printf("TestQuickSort 5K test: ");
	
	TEST("TestQuickSort", test_status, 0);
}
