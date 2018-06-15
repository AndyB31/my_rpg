/*
** EPITECH PROJECT, 2018
** free_all2
** File description:
** free_all2
*/

#include "my_rpg.h"

int free_sprite_inf(sprite_info_t *sprite_inf)
{
	if (sprite_inf == NULL)
		return (0);
	if (sprite_inf->sprite)
		sfSprite_destroy(sprite_inf->sprite);
	if (sprite_inf->texture)
		sfTexture_destroy(sprite_inf->texture);
	if (sprite_inf->id_name)
		free(sprite_inf->id_name);
	free(sprite_inf);
	return (1);
}

int free_text_inf(text_info_t *text_info)
{
	if (text_info == NULL)
		return (0);
	if (text_info->text)
		sfText_destroy(text_info->text);
	if (text_info->font)
		sfFont_destroy(text_info->font);
	if (text_info->id_name)
		free(text_info->id_name);
	free(text_info);
	return (1);
}

int free_inventory(inv_t *inv)
{
	if (inv == NULL)
		return (0);
	if (inv->id)
		free(inv->id);
	free_list(inv->head);
	if (inv->boots)
		free(inv->boots);
	if (inv->chestplate)
		free(inv->chestplate);
	if (inv->gloves)
		free(inv->gloves);
	if (inv->helmet)
		free(inv->helmet);
	if (inv->shield)
		free(inv->shield);
	if (inv->weapon)
		free(inv->weapon);
	return (0);
}

int free_item(item_t *item)
{
	if (item == NULL)
		return (1);
	if (item->attribute)
		free(item->attribute);
	if (item->id)
		free(item->id);
	if (item->texture)
		sfTexture_destroy(item->texture);
	if (item->texture_path)
		free(item->texture_path);
	free(item);
	return (1);
}

int free_item_inf(item_inf_t *item_inf)
{
	if (item_inf == NULL)
		return (1);
	if (item_inf->id)
		free(item_inf->id);
	free(item_inf);
	return (1);
}
