/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/
#include "my_rpg.h"

scene_t *create_scene(scene_type_t type)
{
	scene_t *scene = malloc(sizeof(scene_t));

	if (scene == NULL)
		return (NULL);
	scene->button_list = NULL;
	scene->sprite_list = NULL;
	scene->text_list = NULL;
	scene->type = type;
	scene->background_music = NULL;
	scene->event_key_pressed = NULL;
	scene->event_mouse_button_pressed = NULL;
	scene->event_mouse_button_released = NULL;
	scene->event_mouse_moved = NULL;
	scene->event_mouse_wheel_scroll = NULL;
	scene->event_tick = NULL;
	scene->textfield_list = NULL;
	scene->current_tick = 0;
	scene->event_init = NULL;
	scene->event_init_post = NULL;
	return (scene);
}

scene_t *get_scene_by_type(list_t **list, scene_type_t type)
{
	list_t *curr = NULL;

	if (list == NULL || *list == NULL)
		return (NULL);
	curr = *list;
	while (curr != NULL) {
		if (curr->scene && curr->scene->type == type)
			return (curr->scene);
		curr = curr->next;
	}
	return (NULL);
}

int render_scene(frame_t *frame, list_t **scene_list, scene_type_t type)
{
	scene_t *scene = get_scene_by_type(scene_list, type);
	list_t *list = NULL;

	if (scene == NULL)
		return (-1);
	scene->current_tick++;
	if (scene->current_tick > 20)
		scene->current_tick = 0;
	if (scene->event_tick)
		scene->event_tick(frame, scene);
	list = scene->sprite_list;
	render_all_sprites(list, frame);
	list = scene->button_list;
	render_all_buttons(list, frame);
	list = scene->text_list;
	render_all_texts(list, frame);
	list = scene->textfield_list;
	render_all_textfields(list, frame);
	return (1);
}

int set_scene_to(frame_t *frame, scene_type_t type, bool stop_music)
{
	scene_t *current = NULL;

	if (frame == NULL)
		return (0);
	current = get_scene_by_type(&(frame->scene), frame->curent_scene);
	if (current == NULL)
		return (0);
	if (frame->curr_sound != NULL && stop_music == true)
		sfMusic_stop(frame->curr_sound);
	current = get_scene_by_type(&(frame->scene), type);
	if (current == NULL)
		return (0);
	if (current->event_init)
		current->event_init(frame, current);
	frame->last_scene = frame->curent_scene;
	frame->curent_scene = type;
	should_play_music(current, frame);
	if (current->event_init_post)
		current->event_init_post(frame, current);
	return (1);
}

void init_scenes(list_t **scene_list, frame_t *frame)
{
	init_main_menu_scene(scene_list, frame);
	init_game_scene(scene_list, frame);
	init_option_scene(scene_list, frame);
	init_fight(scene_list, frame);
	init_pause_scene(scene_list, frame);
	init_quest_scene(scene_list, frame);
	init_intro_scene(scene_list, frame);
	init_cutscenes_scene(scene_list, frame);
	init_win_scene(scene_list, frame);
	init_lose_scene(scene_list, frame);
}
