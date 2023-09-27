#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *					  order using the Cocktail Shaker sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				current->next->prev = current->prev;
				temp = current->next->next;
				current->next->next = current;
				current->prev = current->next;
				current->next = temp;

				if (temp != NULL)
					temp->prev = current;

				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				if (current->next != NULL)
					current->next->prev = current->prev;

				current->prev->next = current->next;
				temp = current->prev->prev;
				current->prev->prev = current;
				current->next = current->prev;
				current->prev = temp;

				if (temp != NULL)
					temp->next = current;
				else
					*list = current;

				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	} while (swapped);
}
