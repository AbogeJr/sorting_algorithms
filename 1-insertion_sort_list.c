#include "sort.h"
/**
* insertion_sort_list - function that sorts doubly-linked
* list of integers in ascending order using insertion algorithm
*
* @list: list of nodes
* Return: sorted list
*/

/* the function */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *marker = NULL;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;

	/* assign list value to temp */
	temp = *list;

	/* assign marker point in the array */
	marker = *list;

	while (marker != NULL)
	{
		marker = marker->next;
		/* checks comparison from the marker to the start */
		while (temp->prev && (temp->n < temp->prev->n))
		{
			/* comparison of prev node to temp next node */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				/* swaps */
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			/* prints list after each iteration */
			print_list(*list);
		}
		temp = marker;
	}
}
