/*
** EPITECH PROJECT, 2018
** game_scene_events_2
** File description:
** game_scene_events_2
*/

#include "my_rpg.h"

static void game_key_press_event2(sfKeyEvent event, frame_t *frame)
{
	if (event.code == sfKeyE)
		check_interaction(frame);
	if (frame->event.key.code == sfKeyRight)
		player_move(0, frame);
	if (frame->event.key.code == sfKeyLeft)
		player_move(3, frame);
	if (frame->event.key.code == sfKeyDown)
		player_move(1, frame);
	if (frame->event.key.code == sfKeyUp)
		player_move(2, frame);
}

void game_key_press_event(sfKeyEvent event, frame_t *frame)
{
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);

	if (event.code == sfKeyI) {
		close_chest(frame);
		change_inventory_status(frame, s);
	}
	if (event.code == sfKeyF)
		open_fight(frame);
	if (event.code == sfKeyEscape)
		open_pause_menu(frame);
	if (event.code == sfKeySpace)
		frame->dial_nbr += 1;
	if (event.code == sfKeyD) {
		frame->dial_nbr = 1;
		frame->path = DIALOGUES_START;
	}
	game_key_press_event2(event, frame);
}