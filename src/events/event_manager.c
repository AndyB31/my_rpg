/*
** EPITECH PROJECT, 2017
** event_manager
** File description:
** event_manager
*/

#include "my_rpg.h"

static void scene_event_manager(sfEvent event, frame_t *frame, \
scene_t *scene)
{
	if (event.type == sfEvtTextEntered && scene->textfield_list)
		fill_textfield(event.text, scene);
	if (event.type == sfEvtKeyPressed && scene->event_key_pressed)
		scene->event_key_pressed(event.key, frame);
	if (event.type == sfEvtMouseButtonPressed && \
	scene->event_mouse_button_pressed)
		scene->event_mouse_button_pressed(event.mouseButton, frame);
	if (event.type == sfEvtMouseButtonReleased && \
	scene->event_mouse_button_released)
		scene->event_mouse_button_released(event.mouseButton, frame);
	if (event.type == sfEvtMouseMoved && scene->event_mouse_moved)
		scene->event_mouse_moved(event.mouseMove, frame);
	if (event.type == sfEvtMouseWheelScrolled && \
	scene->event_mouse_wheel_scroll)
		scene->event_mouse_wheel_scroll(event.mouseWheelScroll, \
		frame);
}

void event_manager(sfEvent event, frame_t *frame)
{
	scene_t *scene = NULL;

	if (frame == NULL)
		return;
	scene = get_scene_by_type(&(frame->scene), \
	frame->curent_scene);
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(frame->window);
	if (event.type == sfEvtMouseButtonPressed)
		mouse_button_pressed_manager(event.mouseButton, frame);
	if (event.type == sfEvtMouseButtonReleased)
		mouse_button_released_manager(event.mouseButton, frame);
	if (event.type == sfEvtMouseMoved)
		mouse_button_move_manager(event.mouseMove, frame);
	if (event.type == sfEvtKeyPressed)
		key_manager(event.key, frame);
	if (scene == NULL)
		return;
	scene_event_manager(event, frame, scene);
}
