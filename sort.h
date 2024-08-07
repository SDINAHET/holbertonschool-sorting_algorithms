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

/*0*/
void bubble_sort(int *array, size_t size);

/*1*/
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/*2*/
void selection_sort(int *array, size_t size);
void swap(int *array, size_t i, size_t j);

/*3*/
void quick_sort(int *array, size_t size);
void swap(int *array, size_t i, size_t j)
size_t lomuto_partition(int *array, size_t low, size_t high)
void quick_sort_rec(int *array, size_t low, size_t high);

#endif /* SORT_H */
