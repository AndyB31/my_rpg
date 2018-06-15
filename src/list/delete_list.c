/*
** EPITECH PROJECT, 2018
** delete_list
** File description:
** delete_list
*/

#include "my_rpg.h"

static int delete_first(list_t **head)
{
	if (head == NULL || *head == NULL)
		return (0);
	*head = (*head)->next;
	return (1);
}

static int delete_last(list_t **head)
{
	list_t *beforelast = get_list_by_id(head, get_list_length(head) - 2);

	beforelast->next = NULL;
	return (1);
}

static int delete_element2(list_t **head, int id)
{
	if (id == 0) {
		delete_first(head);
		return (1);
	} else if (id == get_list_length(head) - 1) {
		delete_last(head);
		return (1);
	}
	return (0);
}

list_t *get_list_by_id(list_t **head, int id)
{
	list_t *curr = *head;
	int i = 0;

	while (curr) {
		if (i == id)
			return (curr);
		i++;
	}
	return (NULL);
}

int delete_element(list_t **head, int id)
{
	list_t *tmp = NULL;
	list_t *tmp2 = NULL;

	if (*head == NULL || head == NULL)
		return (0);
	if (delete_element2(head, id) == 0) {
		tmp = get_list_by_id(head, id);
		tmp2 = get_list_by_id(head, id - 1);
		tmp2->next = tmp->next;
	}
	return (1);
}