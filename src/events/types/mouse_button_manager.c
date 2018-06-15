/*
** EPITECH PROJECT, 2018
** mouse_button_manager
** File description:
** mouse_button_manager
*/
#include "my_rpg.h"

int check_music(list_t *curr_button, frame_t *frame)
{
	if (curr_button->button->click_sound && !frame->volume_stop) {
		sfMusic_setVolume(curr_button->button->click_sound, \
		frame->volume_level * 33);
		sfMusic_play(curr_button->button->click_sound);
		return (1);
	}
	return (0);
}

void mouse_button_pressed_manager(sfMouseButtonEvent event, frame_t *frame)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *curr_button = NULL;
	sfVector2f pos = {.x = 0, .y = 0};

	if (event.button != sfMouseLeft || scene == NULL)
		return;
	curr_button = scene->button_list;
	while (curr_button) {
		pos.x = event.x;
		pos.y = event.y;
		if (is_mouse_on_button(*(curr_button->button), pos) && \
		curr_button->button->enabled == true) {
			curr_button->button->status = 2;
		} else {
			curr_button = curr_button->next;
			continue;
		}
		curr_button = curr_button->next;
	}
}

void mouse_button_released_manager(sfMouseButtonEvent event, frame_t *frame)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *curr_button = NULL;
	sfVector2f pos = {0, 0};

	if (event.button != sfMouseLeft || scene == NULL)
		return;
	curr_button = scene->button_list;
	while (curr_button) {
		pos.x = event.x;
		pos.y = event.y;
		if (is_mouse_on_button(*(curr_button->button), pos) == 1\
		&& curr_button->button->click_action != NULL && \
		curr_button->button->enabled == true) {
			curr_button->button->click_action(event.x, event.y, \
			frame, curr_button->button);
		}
		curr_button = curr_button->next;
	}
}

void mouse_button_move_manager(sfMouseMoveEvent event, frame_t *frame)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *curr_button = NULL;
	sfVector2f pos = {0, 0};

	if (scene == NULL)
		return;
	curr_button = scene->button_list;
	while (curr_button) {
		pos.x = event.x;
		pos.y = event.y;
		if (curr_button->button->enabled == false) {
			curr_button = curr_button->next;
			continue;
		}
		if (is_mouse_on_button(*(curr_button->button), pos) \
		&& curr_button->button->hover_action != NULL) {
			curr_button->button->status = 1;
			curr_button->button->hover_action(event.x, event.y, \
			frame, curr_button->button);
		} else if (is_mouse_on_button(*(curr_button->button), pos)) {
			curr_button->button->status = 1;
		} else
			curr_button->button->status = 0;
		curr_button = curr_button->next;
	}
}
