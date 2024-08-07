#include <stdio.h>
#include "sort.h"
/* Bubble Sort algorithm in C task0*/

/**
 * print_array - Prints an array of integers.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *                the Bubble sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
                /* Swap the elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
                /* Print the array after the swap*/
				print_array(array, size);
			}
		}
        /* If no elements were swapped, the array is sorted */
		if (!swapped)
			break;
	}
}
