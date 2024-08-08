#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts a linked list in ascending order using
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

		/*move to the node to its correct position*/
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list); // Optional: For debugging
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: the first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL|| node1 == node2)
		return;

		/*swap the nodes*/
		listint_t *prev1 = node1->prev;
		listint_t *next1 = node1->next;
		listint_t *prev2 = node2->prev;
		listint_t *next2 = node2->next;

		/*adjust pointers*/
		if (prev1)
			prev1->next = node2;
		else
			*list = node2; /*new head if node1 was head*/

		if (next2)
			next2->prev = node1;

		node1->next = next2;
		node1->prev = node2;

		node2->next = next1;
		node2->prev = prev1;

		/*print the list after swap*/
		print_list(*list);
}
