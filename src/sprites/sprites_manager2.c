/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "my_rpg.h"

int render_sprite2(frame_t *frame, sprite_info_t *sprite_inf, sfIntRect rec)
{
	if (frame == NULL || sprite_inf == NULL || \
	sprite_inf->enabled == false)
		return (0);
	if (sprite_inf->is_init)
		sfSprite_move(sprite_inf->sprite , sprite_inf->speed);
	else {
		sfSprite_setPosition(sprite_inf->sprite , sprite_inf->pos);
		sprite_inf->is_init = 1;
	}
	sfSprite_setScale(sprite_inf->sprite, sprite_inf->scale);
	sfSprite_setTexture(sprite_inf->sprite, sprite_inf->texture, sfTrue);
	sfSprite_setTextureRect(sprite_inf->sprite, rec);
	sfRenderWindow_drawSprite(frame->window, sprite_inf->sprite, NULL);
	if (++sprite_inf->current_state >= sprite_inf->total_states)
		sprite_inf->current_state = 0;
	return (1);
}
