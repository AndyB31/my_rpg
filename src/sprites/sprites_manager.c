/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "my_rpg.h"

sprite_info_t *create_sprite(int total_states, sfVector2i size, \
const char *texture_path)
{
	sprite_info_t *element = malloc(sizeof(sprite_info_t));
	sfVector2f scale = {1, 1};
	sfVector2f speed = {0, 0};

	if (element == NULL || texture_path == NULL)
		return (NULL);
	element->texture = sfTexture_createFromFile(texture_path, NULL);
	element->sprite = sfSprite_create();
	element->total_states = total_states;
	element->size = size;
	element->speed = speed;
	element->scale = scale;
	element->current_state = 0;
	element->is_init = 0;
	element->id_name = NULL;
	element->enabled = true;
	element->curr_tick = 0;
	element->tick_max = 0;
	element->vertical_state = 0;
	return (element);
}

int sprite_set_speed(sprite_info_t *sprite_inf, float x, float y)
{
	if (sprite_inf == NULL)
		return (0);
	sprite_inf->speed.x = x;
	sprite_inf->speed.y = y;
	return (1);
}

int sprite_set_scale(sprite_info_t *sprite_inf, float x, float y)
{
	if (sprite_inf == NULL)
		return (0);
	sprite_inf->scale.x = x;
	sprite_inf->scale.y = y;
	return (1);
}

int sprite_set_pos(sprite_info_t *sprite_inf, float x, float y)
{
	if (sprite_inf == NULL)
		return (0);
	sprite_inf->pos.x = x;
	sprite_inf->pos.y = y;
	sprite_inf->is_init = 0;
	return (1);
}
