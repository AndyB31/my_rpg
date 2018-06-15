/*
** EPITECH PROJECT, 2018
** get_list_length
** File description:
** get_list_length
*/

#include "my_rpg.h"

int get_list_length(list_t **head)
{
	list_t *curr = NULL;
	int i = 0;

	if (head == NULL || *head == NULL)
		return (0);
	curr = *head;
	while (curr) {
		i++;
		curr = curr->next;
	}
	return (i);
}