/*
** EPITECH PROJECT, 2018
** add_item_to_inv
** File description:
** add_item_to_inv
*/

#include "my_rpg.h"

static item_inf_t *add_item_to_list(inv_t *inv, char *id, int nbr)
{
	list_t **head = &(inv->head);
	list_t *element = create_list();
	list_t *curr = NULL;
	int slot_id = get_slot_id(inv);

	if (element == NULL || slot_id < 0)
		return (NULL);
	curr = *head;
	element->item_inf = init_item_inf(id, nbr, slot_id);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (element->item_inf);
}

static int add_item_to_item_inf(item_inf_t *item_info, int max_size, int nbr)
{
	if (nbr <= 0)
		return (0);
	if (item_info->nbr + 1 > max_size)
		return (nbr);
	item_info->nbr += 1;
	return (add_item_to_item_inf(item_info, max_size, nbr - 1));
}

static item_inf_t *add_sort_item(inv_t *inv, char *id, int nbr, frame_t *f)
{
	item_t *real_item = NULL;
	int result = 0;

	if (nbr <= 0)
		return (NULL);
	if (f == NULL)
		return (add_item_to_list(inv, id, nbr));
	real_item = get_item_by_id(&(f->item_list), id);
	if (real_item == NULL)
		return (NULL);
	result = nbr / real_item->stack_size;
	for (int i = 0; i < result; i++) {
		if (get_list_length(&(inv->head)) > inv->size_max)
			return (NULL);
		add_item_to_list(inv, id, real_item->stack_size);
		nbr -= real_item->stack_size;
	}
	if (nbr <= 0)
		return (NULL);
	return (add_item_to_list(inv, id, nbr));
}

item_inf_t *add_item_to_inv(inv_t *inv, char *id, int nbr, frame_t *f)
{
	item_inf_t *item = NULL;
	int result = 0;
	item_t *real_item = NULL;

	if (get_list_length(&(inv->head)) > inv->size_max)
			return (NULL);
	if (inv == NULL || id == NULL || nbr <= 0)
		return (NULL);
	item = can_add_item(inv, id, nbr, f);
	if (item == NULL || f == NULL) {
		if (get_list_length(&(inv->head)) > inv->size_max)
			return (NULL);
		return (add_sort_item(inv, id, nbr, f));
	}
	real_item = get_item_by_id(&(f->item_list), id);
	if (real_item == NULL)
		return (NULL);
	result = add_item_to_item_inf(item, real_item->stack_size, nbr);
	return (add_item_to_inv(inv, id, result, f));
}

item_inf_t *add_item_inf_to_list(inv_t *inv, item_inf_t *inf)
{
	list_t **head = &(inv->head);
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL || inf->slot_id < 0)
		return (NULL);
	curr = *head;
	element->item_inf = inf;
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (element->item_inf);
}
