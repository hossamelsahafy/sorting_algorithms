#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - function  that sorts a doubly linked list
 * of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: parameter that point to listint_t
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;

	if (list == NULL || *list == NULL)
		return;
	cur = (*list)->next;
	while (cur != NULL)
	{
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			tmp = cur;
			if (cur->next != NULL)
				cur->next->prev = tmp->prev;
			cur->prev->next = tmp->next;
			if (tmp->prev->prev == NULL)
				*list = tmp;
			else
				tmp->prev->prev->next = tmp;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			print_list((const listint_t *)*list);
		}
		cur = cur->next;
	}
}
