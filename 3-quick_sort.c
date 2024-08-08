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
 * lomuto_partition - Partitions the array using Lomuto's scheme.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t size = sizeof(array);
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				/* Print array after swap */
				/*print_array(array, high - low + 1); error*/
				/*print_array(array, size + 2);*/
				print_array(array, size + 2);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(array, i, high);
		/* Print array after swap */
		/*print_array(array, high - low + 1);  error*/
		print_array(array, size + 2);
	}

	/* Print the array after the partitioning is done */
	/*printf("Partitioning with pivot %d: ", pivot); error*/
	/*print_array(array + low, high - low + 1);error*/
	/*print_array(array, high - low + 1);error*/
	/*print_array(array, 10); solution SD 08/08/24 19h30*/
	/*print_array(array, size + 2); solution SD 08/08/24 19h49*/
	/*printf("  Elements below the pivot (%d): ", pivot);*/
	/*print_array(array, size);*/

	return (i);
}

/**
 * quick_sort_rec - Recursively sorts the array using quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the segment to sort.
 * @high: Ending index of the segment to sort.
 */
void quick_sort_rec(int *array, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pi = lomuto_partition(array, low, high);

		if (pi > 0)
			quick_sort_rec(array, low, pi - 1);
		quick_sort_rec(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using quick sort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_rec(array, 0, size - 1);
}
