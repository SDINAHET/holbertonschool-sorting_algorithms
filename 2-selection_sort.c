#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                the Selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	/* Check if the array has less than 2 elements, no need to sort */
	if (size < 2)
		return;

	/* Iterate through each element in the array */
	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;

		/* Find the index of the smallest element in the unsorted portion */
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		/* Swap the found minimum element with the first element of the*/
		/*unsorted portion */
		if (min_index != i)
		{
			swap(array, i, min_index);

			/* Print the array after each swap */
			for (j = 0; j < size; ++j)
			{
				printf("%d", array[j]);
				if (j < size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
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
