/*
** EPITECH PROJECT, 2018
** read_inventory
** File description:
** read_inventory
*/

#include "my_rpg.h"

static int read_inventory_content(int fd, inv_t *inventory, int size)
{
	char *item_name = NULL;
	int nbr_item = 0;
	int slot_id = 0;
	item_inf_t *item = NULL;

	for (int i = 0; i < size; i++) {
		item_name = read_str_fd(fd);
		nbr_item = read_nbr_fd(fd);
		slot_id = read_nbr_fd(fd);
		item = init_item_inf(item_name, nbr_item, slot_id);
		add_item_inf_to_list(inventory, item);
	}
	return (1);
}

static int read_inventory_armor(int fd, inv_t *inv)
{
	inv->boots = read_str_fd(fd);
	inv->chestplate = read_str_fd(fd);
	inv->gloves = read_str_fd(fd);
	inv->helmet = read_str_fd(fd);
	inv->shield = read_str_fd(fd);
	inv->weapon = read_str_fd(fd);
	return (1);
}

static inv_t *read_inventory2(int fd, inv_t *inventory)
{
	char *id_read = NULL;
	int size_max_read = 0;
	int size = 0;

	id_read = read_str_fd(fd);
	size_max_read = read_nbr_fd(fd);
	inventory = create_inventory(id_read, size_max_read);
	read_inventory_armor(fd, inventory);
	size = read_nbr_fd(fd);
	read_inventory_content(fd, inventory, size);
	close(fd);
	return (inventory);
}

inv_t *read_inventory(char *id)
{
	int fd = 0;
	char *new_path = NULL;
	inv_t *inventory = NULL;

	if (id == NULL)
		return (NULL);
	new_path = my_strcat("./data/inventory/", id);
	if (new_path == NULL)
		return (NULL);
	fd = open(new_path, O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	free(new_path);
	if (fd < 0)
		return (NULL);
	return (read_inventory2(fd, inventory));
}
