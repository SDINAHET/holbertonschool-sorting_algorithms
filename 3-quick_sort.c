#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order using
 *               the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return; /* No need to sort if the array has less than 2 elements */

	quick_sort_rec(array, 0, size - 1);
}

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing the elements to swap.
 * @i: The index of the first element.
 * @j: The index of the second element.
 *
 * This function exchanges the values of array[i] and array[j].
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * The pivot is always the last element of the partition.
 * This function rearranges the array so that all elements less than the pivot
 * are before it and all elements greater than the pivot are after it.
 * It returns the index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j);
			i++;
		}
	}
	swap(array, i, high);

	/* Print the array after partitioning */
	for (j = 0; j < high + 1; ++j)
	{
		printf("%d", array[j]);
		if (j < high)
			printf(", ");
	}
	printf("\n");

	return i;
}

/**
 * quick_sort_rec - Recursively applies the Quick sort algorithm.
 * @array: The array to sort.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 */
void quick_sort_rec(int *array, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);
		if (pivot_index > 0)
		{
			quick_sort_rec(array, low, pivot_index - 1);
		}
		quick_sort_rec(array, pivot_index + 1, high);
	}
}
