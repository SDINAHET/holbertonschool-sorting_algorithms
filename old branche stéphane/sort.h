#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*print_array.c*/
void print_list(const listint_t *list);

/*print_list.c*/
void print_array(const int *array, size_t size);

/*prototype*/

/*1*/
void bubble_sort(int *array, size_t size);

/*2*/
void insertion_sort_list(listint_t **list);

/*3*/
void selection_sort(int *array, size_t size);

/*4*/
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
