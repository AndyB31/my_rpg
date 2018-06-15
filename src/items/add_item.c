/*
** EPITECH PROJECT, 2018
** add_item
** File description:
** add_item
*/

#include "my_rpg.h"

int add_item(list_t **head, item_t *item)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (0);
	curr = *head;
	element->item = item;
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (1);
}
