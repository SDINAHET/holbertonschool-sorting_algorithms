#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort2 - Sorts a doubly linked list in ascending order using
 *                       the Insertion sort algorithm.
 * @array: pointer to the head of the linked list to sort.
 */
void insertion_sort_array(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return; /* No sort if the array is NUL less than 2 elements*/
	}

	/* Start from the second element*/
	for (size_t i = 1; i < size; i++)
	{
		int value = array[i]; /* Element to be inserted*/
		size_t j = i;		  /* Position to insert the element*/

		/*swap elements of the sorted portion to the right*/
		while (j > 0 && array[j - 1] > value)
		{
			array[j] = array[j - 1];
			j--;
		}

		/*Insert the value at its correct position*/
		array[j] = value;

		/* Print the array after each insertion*/
		print_array(array, size);
	}
}

/**
 * swap - Swaps two elements in an array
 * @array: Pointer to the array of integers
 * @i: Index of the first element to swap
 * @j: Index of the second element to swap
 *
 * Description: This function swaps the elements at indices
 *               @i and @j in the array.
 */
/* Function to swap two elements in an array */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*gcc -Wall -Wextra -Werror -pedantic 1-main_array.c 1-insertion_sort_array.c print_array.c -o insertion2*/
