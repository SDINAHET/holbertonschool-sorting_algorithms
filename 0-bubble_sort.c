#include <stdio.h>
#include "sort.h"
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

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements 3 step*/

				/* Stocker l'élément temporairement*/
				temp = array[j];
				/*Déplacer l'élément suivant vers l'index actuel*/
				array[j] = array[j + 1];
				/*Placer l'élément stocké à la position suivante*/
				array[j + 1] = temp;

				/* Print the array after the swap*/
				print_array(array, size);
			}
		}
	}
}
