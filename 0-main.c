#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n); /*1er array 19, 48, 99, 71, 13, 52, 96, 73, 86, 7*/
	printf("\n");
	bubble_sort(array, n); /*trie bubble en array*/
	printf("\n");
	print_array(array, n); /*2ème array 7, 13, 19, 48, 52, 71, 73, 86, 96, 99*/
	return (0);
}
