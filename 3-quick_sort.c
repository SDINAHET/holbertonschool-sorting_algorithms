#include "sort.h"
#include <stdio.h>

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
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The new index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j) /* Only swap if i and j are different*/
			{
				swap(array, i, j);
				print_array(array, size); /* Print array after swap*/
			}
		}
	}

	if (i + 1 != high) /* Only swap if i + 1 and high are different*/
	{
		swap(array, i + 1, high);
		print_array(array, size); /* Print array after final swap*/
	}

	return (i + 1);
}

/**
 * quick_rec - Recursively sorts the array using quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the segment to sort.
 * @high: Ending index of the segment to sort.
 * @size: The size of the array.
 */
void quick_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		if (pi > low)
			quick_rec(array, low, pi - 1, size);
		if (pi < high)
			quick_rec(array, pi + 1, high, size);
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

	quick_rec(array, 0, size - 1, size);
}
