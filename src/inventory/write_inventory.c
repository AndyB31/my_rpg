/*
** EPITECH PROJECT, 2018
** write_inventory
** File description:
** write_inventory
*/

#include "my_rpg.h"

static int write_armor_inventory(int fd, inv_t *inv)
{
	write_str_fd(fd, inv->boots);
	write_str_fd(fd, inv->chestplate);
	write_str_fd(fd, inv->gloves);
	write_str_fd(fd, inv->helmet);
	write_str_fd(fd, inv->shield);
	write_str_fd(fd, inv->weapon);
	return (1);
}

static int write_inventory2(inv_t *inv, int fd)
{
	int length = 0;
	list_t *curr = NULL;
	int i = 0;

	length = get_list_length(&(inv->head));
	curr = inv->head;
	write_str_fd(fd, inv->id);
	write_nbr_fd(fd, inv->size_max);
	write_armor_inventory(fd, inv);
	write_nbr_fd(fd, length);
	while (curr && i < get_list_length(&(inv->head))) {
		write_str_fd(fd, curr->item_inf->id);
		write_nbr_fd(fd, curr->item_inf->nbr);
		write_nbr_fd(fd, curr->item_inf->slot_id);
		curr = curr->next;
		i++;
	}
	close(fd);
	return (0);
}

int write_inventory(inv_t *inv)
{
	char *path = NULL;
	int fd = -1;

	if (inv == NULL)
		return (1);
	path = my_strcat("./data/inventory/", inv->id);
	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, \
	S_IRWXU | S_IRWXG | S_IRWXO);
	free(path);
	if (fd < 0)
		return (1);
	return (write_inventory2(inv, fd));
}
