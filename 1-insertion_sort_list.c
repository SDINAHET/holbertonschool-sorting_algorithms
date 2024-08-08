#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1 = node1->prev;
	listint_t *next2 = node2->next;

	if (node1 == NULL || node2 == NULL || node1 == node2)
	{
		return;
	}

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;

	if (next2)
		next2->prev = node1;

	node1->next = next2;
	node1->prev = node2;

	node2->next = node1;
	node2->prev = prev1;
}
