/*
** EPITECH PROJECT, 2018
** create_list
** File description:
** create_list
*/

#include <my_rpg.h>

list_t *create_list(void)
{
	list_t *element = malloc(sizeof(list_t));

	if (element == NULL)
		return (NULL);
	element->textfield = NULL;
	element->button = NULL;
	element->scene = NULL;
	element->sprite_inf = NULL;
	element->id = 0;
	element->next = NULL;
	element->text_inf = NULL;
	element->item = NULL;
	element->item_inf = NULL;
	element->id_name = NULL;
	return (element);
}
