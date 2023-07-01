#include "sort.h"

/**
 * _nodeSwap - Function to switch nodes
 * @h: Pointer to the first node
 * @node1: The first node
 * @node2: The other node for swap
 *
 * Return: Nothing
 */
void _nodeSwap(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Insertion sort algorith on doubly linked list
 * @list: The list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && current->n < prev_node->n)
		{
			_nodeSwap(list, &prev_node, current);
			print_list((const listint_t *)*list);
		}
	}
}
