/*
** EPITECH PROJECT, 2018
** render_sprite
** File description:
** render_sprite
*/

#include "my_rpg.h"

static int render_sprite_2(frame_t *frame, sprite_info_t *sprite_inf)
{
	if (sprite_inf->curr_tick >= sprite_inf->tick_max) {
		if (++sprite_inf->current_state >= sprite_inf->total_states)
			sprite_inf->current_state = 0;
		sprite_inf->curr_tick = 0;
	}
	sprite_inf->curr_tick++;
	return (0);
}

int render_sprite(frame_t *frame, sprite_info_t *sprite_inf)
{
	sfIntRect rec = {sprite_inf->size.x * sprite_inf->current_state,
	sprite_inf->vertical_state * sprite_inf->size.y, sprite_inf->size.x, \
	sprite_inf->size.y};

	if (frame == NULL || sprite_inf == NULL || \
	sprite_inf->enabled == false)
		return (0);
	if (sprite_inf->is_init) {
		sfSprite_move(sprite_inf->sprite , sprite_inf->speed);
	} else {
		sfSprite_setPosition(sprite_inf->sprite , sprite_inf->pos);
		sprite_inf->is_init = 1;
	}
	sfSprite_setScale(sprite_inf->sprite, sprite_inf->scale);
	sfSprite_setTexture(sprite_inf->sprite, sprite_inf->texture, sfTrue);
	if (sprite_inf->size.x >= 0 && sprite_inf->size.y >= 0)
		sfSprite_setTextureRect(sprite_inf->sprite, rec);
	sfRenderWindow_drawSprite(frame->window, sprite_inf->sprite, NULL);
	return (render_sprite_2(frame, sprite_inf));
}