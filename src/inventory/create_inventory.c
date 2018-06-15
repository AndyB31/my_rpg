/*
** EPITECH PROJECT, 2018
** create_inventory
** File description:
** create_inventory
*/

#include "my_rpg.h"

bool is_file_in_dir(char *name, char *dir_path)
{
	DIR *dir = opendir(dir_path);
	struct dirent *file = NULL;
	bool b = false;

	if (dir == NULL)
		return (false);
	while ((file = readdir(dir)) != NULL)
		if (my_are_equals(file->d_name, name))
			b = true;
	closedir(dir);
	return (b);
}

inv_t *create_inventory(char *id, int size_max)
{
	inv_t *inventory = malloc(sizeof(inv_t));

	if (inventory == NULL)
		return (NULL);
	inventory->id = malloc((my_strlen(id) + 1) * sizeof(char));
	if (inventory->id == NULL)
		return (NULL);
	inventory->id = my_strcpy(inventory->id, id);
	inventory->size_max = size_max;
	inventory->head = NULL;
	inventory->boots = NULL;
	inventory->chestplate = NULL;
	inventory->gloves = NULL;
	inventory->helmet = NULL;
	inventory->shield = NULL;
	inventory->weapon = NULL;
	return (inventory);
}
