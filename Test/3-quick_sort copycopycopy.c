#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * swap - Swaps two elements in an array.
 * @array: Pointer to the array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The new index of the pivot
 */
int lomuto_partition(int *array, size_t low, size_t high, , size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j);
			print_array(array, size); /* Print array after swap*/
			i++;
		}
	}

	swap(array, i + 1, high);
	print_array(array, size); /* Print array after final swap*/

	return (i + 1);
}

/**
 * quick_rec - Recursively sorts the array using quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the segment to sort.
 * @high: Ending index of the segment to sort.
 */
void quick_rec(int *array, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pi = lomuto_partition(array, low, high, high - low + 1);
		
		if (pi > low)
			quick_rec(array, low, pi - 1);
		if (pi < high)
			quick_rec(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using quick sort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_rec(array, 0, size - 1);
}
