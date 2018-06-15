/*
** EPITECH PROJECT, 2018
** create_item
** File description:
** create_item
*/

#include "my_rpg.h"

item_t *create_item(char *id, enum item_type type, int stack_size, \
char *texture)
{
	item_t *item = malloc(sizeof(item_t));

	if (item == NULL)
		return (NULL);
	item->id = malloc((my_strlen(id) + 1) * sizeof(char));
	if (item->id == NULL)
		return (NULL);
	item->id = my_strcpy(item->id, id);
	item->type = type;
	item->texture_path = malloc((my_strlen(texture) + 1) * sizeof(char));
	if (item->texture_path == NULL)
		return (NULL);
	item->texture_path = my_strcpy(item->texture_path, texture);
	item->texture = sfTexture_createFromFile(item->texture_path, NULL);
	item->stack_size = stack_size;
	item->attribute = NULL;
	item->desc = read_value_file(PATH_ITEM_DESC, id);
	item->name = read_value_file(PATH_ITEM_NAME, id);
	return (item);
}
