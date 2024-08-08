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
 * print_subarray - Prints a subarray from index low to high.
 * @array: Pointer to the array.
 * @low: Starting index of the subarray.
 * @high: Ending index of the subarray.
 */
void print_subarray(const int *array, size_t low, size_t high)
{
	size_t i;

	for (i = low; i <= high; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * print_partition - Print the array with a range.
 * @array: Pointer to the array.
 * @low: Starting index of the range.
 * @high: Ending index of the range.
 */
void print_partition(const int *array, size_t low, size_t high)
{
	for (size_t i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
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
	size_t i = low;
	size_t j;

	printf("Initial array:\n");
	print_partition(array, low, high);

	printf("Partitioning with pivot %d:\n", pivot);

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				/* Print array after swap */
				printf("After swapping %d and %d:\n", array[i], array[j]);
				print_partition(array, low, high);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(array, i, high);
		/* Print array after placing the pivot */
		printf("After moving pivot %d to position %zu:\n", pivot, i);
		print_partition(array, low, high);
	}

	/* Print the array after the partitioning is done */
	printf("Array after partitioning with pivot %d:\n", pivot);
	print_partition(array, low, high);

	return i;
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
