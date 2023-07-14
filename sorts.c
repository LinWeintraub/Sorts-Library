/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ *
 ~ Author        Lin Weintraub                                   ~
 * Version       2.0.0                                           *
 ~ Date          1/12/22                                         ~
 * Description   Sorts                                           *
 * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */
 
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <assert.h> /* asser */
#include <string.h> /*memcpy*/

#include "sorts.h"

#define DEC_BASE 10

/*---------------------------Function Declarations----------------------------*/
static void Swap(int *x, int *y);
static int FindMin(int *array, size_t length);
static int FindMax(int *array, size_t length);
static void ArrCpy(int *dest, int *src, size_t length);
static void RadixCountingSort(int *array, size_t length, int exp);
static int CountDigits(int number);
static long BinarySRec(int *array, int *from, int *to, int value);
static int MergeSortedArrays(int *array_left,
						int *array_right,
						size_t right_size,
						size_t left_size);
static void *Partition(void *array,
						size_t lenght,
						size_t element_size,
						int (*cmp_func)(const void *, const void*));
static void GenericSwap(void *ptr_1, void *ptr_2, size_t size);


/*---------------------------------API-Functions------------------------------*/
void BubbleSort(int *array, size_t length)
{
	size_t i = 0;
	size_t j = 0;
    int is_swapped = 1;
    
	assert(array);
		
    for (i = 0; is_swapped == 1 && i < length - 1; ++i)
    {
    		is_swapped = 0;
		    for (j = 0; j < (length - 1) - i; ++j)
		    {
		        if (array[j] > array[j + 1])
		        {
		            Swap(&array[j], &array[j + 1]);
		            is_swapped = 1;
		        }
		    }
    }
}
/*----------------------------------------------------------------------------*/
void SelectionSort(int *array, size_t length)
{
	size_t min_idx = 0;
	size_t i = 0;
	size_t j = 0;
	
	assert(array);
	
    for (i = 0; i < length - 1; ++i)
    {
        min_idx = i;
        
        for (j = i + 1; j < length; ++j)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        
        Swap(&array[min_idx], &array[i]);
    }
}
/*----------------------------------------------------------------------------*/
void InsertionSort(int *array, size_t length)
{
	size_t i = 0;	
	size_t j = 0;
	
	assert(array);
		
	for (i = 1; i < length; ++i)
	{
		j = i; 
		
		while (j > 0 && array[j - 1] > array[j]) 
		{
        	Swap(&array[j], &array[j - 1]);
			j--;
		}
	}
}
/*----------------------------------------------------------------------------*/
void CountSort(int *array, size_t length)
{
	size_t i = 0;
	
	int *count_array = NULL;
	size_t count_array_range = 0;
	
	int *sorted_array = NULL;
	size_t sorted_array_pos = 0;
	
	int min = array[0];
	int max = array[0];
	
	assert(array);	
	
	/*find range for count_array array*/ 
	max = FindMax(array ,length);
	min = FindMin(array ,length);

	count_array_range = max - min + 1;
	count_array = calloc(count_array_range, sizeof(size_t));
	if (NULL == count_array)
	{
		return;
	}
	
	sorted_array = calloc(length, sizeof(int));
	if (NULL == sorted_array)
	{
		free(count_array); count_array = NULL;
		return;
	}
	
	/*count instances of each value in array*/
	for (i = 0; i < length; ++i)
	{	
		++count_array[array[i] - min];
	}
	
	/*sum count_array array*/
	for (i = 1; i < count_array_range; ++i)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}	
	
	for (i = length -1; i > 0; --i) 
	{
		sorted_array_pos = --count_array[array[i] - min];
		sorted_array[sorted_array_pos] = array[i];
	}
	sorted_array_pos = --count_array[array[0] - min];
	sorted_array[sorted_array_pos] = array[0];
	
	/*copy sorted_array back to original array*/
	ArrCpy(array, sorted_array, length);
	
	free(count_array); count_array = NULL;
	free(sorted_array); sorted_array = NULL;
}
/*----------------------------------------------------------------------------*/
void RadixSort(int *array, size_t length)
{
	size_t i = 0;
	int max = array[0];
	size_t max_digits = 0;
	size_t exp = 1; 
		
	assert(array);
	
	max = FindMax(array, length);
	max_digits = CountDigits(max);

	for (i = 0; i < max_digits; ++i)
	{
		RadixCountingSort(array, length, exp);
		exp = exp * DEC_BASE;
	}
}
/*----------------------------------------------------------------------------*/
long BinarySearchIter(int *array, size_t length, int value)
{
	int *from = NULL;
	int *to = NULL;
	int *mid = 0;

	assert(array);
	assert(length);

	from = array;
	to = array + (length - 1);

	while (from <= to)
	{   
		mid = array + (((to - array) + (from - array)) / 2); 
		if (value == *mid)
		{
			return (long)(mid - array);
		}

		else if (value > *mid)
		{
			from = mid + 1;
		}
			
		else
		{
			to = mid - 1;
		}
	}

	return -1;
}
/*----------------------------------------------------------------------------*/
long BinarySearchRec(int *array, size_t length, int value)
{
	int *from = NULL;
	int *to = NULL;

	assert(array);
	assert(length);

	from = array;
	to = array + (length - 1);

	return (BinarySRec(array, from, to, value));
}
/*----------------------------------------------------------------------------*/
int MergeSort(int *array, size_t length)
{
	int status = 0;
	size_t right_size = 0; 
	size_t left_size = 0;

	assert(array);
	assert(length);

	right_size = length / 2; 
	left_size = length - right_size;

	if (length < 2)
	{
		return status;
	}

	else
	{
		MergeSort(array, right_size);
		MergeSort((array + right_size), left_size);
		status = MergeSortedArrays(array,
									(array + right_size),
									right_size,
									left_size);
	}

	return status;
}
/*----------------------------------------------------------------------------*/
void QuickSort(void *array, 
               size_t length, 
               size_t element_size, 
               int (*cmp_func)(const void *left, const void *right))
{
	void *pivot = NULL;
	size_t sub_arr_size = 0 ;

	assert(array);
	assert(element_size);
	assert(cmp_func);

	if (length < 2)
	{
		return;
	}

	pivot = Partition(array, length, element_size, cmp_func);
	sub_arr_size = ((char *)pivot - (char *)array) / element_size;

	QuickSort(array, sub_arr_size, element_size, cmp_func);
	QuickSort((char *)pivot + element_size,
				length - sub_arr_size - 1, 
				element_size, 
				cmp_func);
}

/*----------------------Static-Function----------------------*/
static void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

static int FindMin(int *array, size_t length)
{
	size_t j = 0;
	int min = array[0];
	
	for (j = 0; j < length; j++) 
	{		
		if (array[j] < min)
		{
			min = array[j];
		}
	}
	
	return min;
}

static int FindMax(int *array, size_t length)
{
	size_t j = 0;
	int max = array[0];
	
	for (j = 0; j < length; j++) 
	{		
		if (array[j] > max)
		{
			max = array[j];
		}
	}
	
	return max;
}

static void ArrCpy(int *dest, int *src, size_t length)
{
	while (length > 0)
	{
		dest[length - 1] = src[length - 1];
		--length;
	}
}

static void RadixCountingSort(int *array, size_t length, int exp) 
{  
	int *sorted_array = NULL;  
	size_t sorted_array_pos = 0;
	int count_array[DEC_BASE] = {0}; 
	size_t i = 0;   
  	
	assert(array);
	
	sorted_array = calloc(length, sizeof(size_t));
	if (NULL == sorted_array)
	{
		return;
	}
	
  	/*count instances of each value in arr*/
	for (i = 0; i < length; ++i)  
	{
		++count_array[(array[i] / exp) % DEC_BASE];  
	}
	
	/*sum count_array*/
	for (i = 1; i < DEC_BASE; ++i) 
	{ 
		count_array[i] = count_array[i] + count_array[i - 1];  
	}

	for (i = length - 1; i > 0; --i) 
	{  	
		sorted_array_pos = --count_array[(array[i] / exp) % DEC_BASE];
		sorted_array[sorted_array_pos] = array[i];
		
	}
	sorted_array_pos = --count_array[(array[0] / exp) % DEC_BASE];
	sorted_array[sorted_array_pos] = array[0];

	
	/*copy target back to original array*/
	ArrCpy(array, sorted_array, length);
	
	free(sorted_array); sorted_array = NULL;
}

static int CountDigits(int number)
{
	int counter = 0;
	
	if (number == 0)
	{
		return 1;
	}
	
	while (number != 0)
	{
		number = number / DEC_BASE;
		++counter;
	}
	
	return counter;
}

static long BinarySRec(int *array, int *from, int *to, int value)
{
	int *mid = NULL;

	assert(array);
	assert(from);
	assert(to);

	if (from > to)
	{
		return -1;
	}

	mid = array + (((to - array) + (from - array)) / 2); 

	if (value == *mid)
	{
		return (long)(mid - array);
	}

	else if (value > *mid)
	{
		return(BinarySRec(array, mid + 1, to, value));
	}
		
	else
	{
		return(BinarySRec(array, from, mid - 1, value));
	}
}

static int MergeSortedArrays(int *array_left, int *array_right, size_t size_left, size_t size_right)
{
	int total_size = 0;
	int *runner_right = NULL;
	int *runner_left = NULL;
	int *temp_runner = NULL;
	int *sorted_temp_arr = NULL;

	assert(array_left);
	assert(array_right);
	assert(size_right);
	assert(size_left);

	total_size = size_right + size_left;
	runner_right = array_right;
	runner_left = array_left;
	sorted_temp_arr = malloc(total_size * sizeof(int));

	if (NULL == sorted_temp_arr)
	{
		return -1;
	}

	temp_runner = sorted_temp_arr;

	while (runner_left < (array_left + size_left) && runner_right < (array_right + size_right))
	{
		if (*runner_left <= *runner_right)
		{
			*temp_runner = *runner_left;
			++runner_left;
		}

		else
		{
			*temp_runner = *runner_right;
			++runner_right;
		}

		++temp_runner;
	}

	while (runner_left < (array_left + size_left))
	{
		*temp_runner = *runner_left;
		++runner_left;
		++temp_runner;
	}

	while (runner_right < (array_right + size_right))
	{
		*temp_runner = *runner_right;
		++runner_right;
		++temp_runner;
	}

	temp_runner = sorted_temp_arr;

	while (total_size)
	{
		*array_left = *temp_runner;
		++array_left;
		++temp_runner;
		--total_size;
	}

	free(sorted_temp_arr);

	return 0;
}

static void *Partition(void *array, size_t lenght, size_t element_size, int (*cmp_func)(const void *, const void*))
{
	void *pivot = NULL;
	int cmp_status_l = 0;
	int cmp_status_r = 0;
	char *left = NULL;
	char *right = NULL;

	assert(array);
	assert(element_size);
	assert(cmp_func);

	pivot = array;
	left = (char *)array + element_size;
	right = (char *)array + ((lenght - 1) * element_size);

	while (right > left)
	{
		cmp_status_r = cmp_func(pivot, right);
		cmp_status_l = cmp_func(pivot, left);

		if (cmp_status_r <= 0)
		{
			right -= element_size;
		}
		
		else if (cmp_status_l > 0)
		{
			left += element_size;
		}
		
		GenericSwap(left, right, element_size);
	}

	while (cmp_func(pivot, right) < 0)
	{
		right -= element_size;
	}

	GenericSwap(pivot, right, element_size);

	return right;
}

static void GenericSwap(void *ptr_1, void *ptr_2, size_t element_size)
{
	char temp = 0;
	char *ch_ptr1 = NULL;
	char *ch_ptr2 = NULL;

	assert(ptr_1);
	assert(ptr_2);

	ch_ptr1 = (char *)ptr_1;
	ch_ptr2 = (char *)ptr_2;
	
	while (element_size != 0)
	{
		memcpy(&temp, ch_ptr1, 1);
		*ch_ptr1 = *ch_ptr2;
		*ch_ptr2 = temp;
		++ch_ptr1;
		++ch_ptr2;
		--element_size;
	}
}

