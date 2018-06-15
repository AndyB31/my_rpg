/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/

#include "my_rpg.h"

static frame_t *init2(frame_t *frame)
{
	frame->path = NULL;
	frame->dial_nbr = 1;
	frame->cutscene = NULL;
	frame->curr_cutscene = NULL;
	frame->curr_chest = NULL;
	frame->last_scene = GAME;
	frame->is_new_player = 0;
	frame->volume_level = 50;
	frame->volume_stop = 0;
	frame->curr_sound = NULL;
	frame->item_list = NULL;
	frame->player = NULL;
	return (frame);
}

frame_t *init(int width, int height)
{
	frame_t *frame = malloc(sizeof(frame_t));
	sfVideoMode mode = {width, height, 32};

	if (frame == NULL)
		return (NULL);
	frame->width = width;
	frame->height = height;
	frame->scene = NULL;
	frame->curent_scene = INTRO;
	frame->window = sfRenderWindow_create(mode, "my_rpg - 2017", \
	sfClose | sfFullscreen, NULL);
	frame->clock = sfClock_create();
	sfRenderWindow_setFramerateLimit(frame->window, 60);
	srand(3345678987);
	frame->map = malloc(sizeof(map_t) * 14);
	init_all_maps(frame->map);
	return (init2(frame));
}

void game_loop(frame_t *frame)
{
	sfColor color = {66, 77, 105, 255};

	if (frame == NULL)
		return;
	if (frame->curent_scene == GAME)
		sfRenderWindow_clear(frame->window, color);
	else
		sfRenderWindow_clear(frame->window, sfBlack);
	if (frame->curent_scene == GAME) {
		move_player(frame);
		display_map (frame);
	}
	render_scene(frame, &(frame->scene), frame->curent_scene);
	sfRenderWindow_display(frame->window);
	sfClock_restart(frame->clock);
}

void display_frame(int width, int height)
{
	frame_t *frame = init(width, height);

	if (frame == NULL)
		return;
	init_scenes(&(frame->scene), frame);
	register_items(frame);
	register_inventory(frame);
	player_manager(frame);
	init_player(frame);
	set_scene_to(frame, INTRO, sfTrue);
	while (sfRenderWindow_isOpen(frame->window)) {
		while (sfRenderWindow_pollEvent(frame->window, \
		&(frame->event)))
			event_manager(frame->event, frame);
		if (sfClock_getElapsedTime(frame->clock).microseconds \
		>= 50000) {
			game_loop(frame);
		}
	}
	free_frame(frame);
}
