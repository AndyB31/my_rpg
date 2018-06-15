/*
** EPITECH PROJECT, 2017
** button_manager
** File description:
** button_manager
*/
#include "my_rpg.h"

button_t *create_button(sfVector2f position, sfVector2f size)
{
	button_t *button = malloc(sizeof(button_t));

	if (button == NULL)
		return (NULL);
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setSize(button->rect, size);
	button->texture_base = NULL;
	button->texture_hover = NULL;
	button->texture_clicked = NULL;
	button->click_action = NULL;
	button->hover_action = NULL;
	button->click_sound = NULL;
	button->status = 0;
	button->texture_status = 0;
	button->enabled = true;
	button->id_name = NULL;
	return (button);
}

int is_mouse_on_button(button_t button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button.rect).x
		+ sfRectangleShape_getSize(button.rect).x &&
		clickPosition.x > sfRectangleShape_getPosition(button.rect).x
		&&
		clickPosition.y < sfRectangleShape_getPosition(button.rect).y
		+ sfRectangleShape_getSize(button.rect).y &&
		clickPosition.y > sfRectangleShape_getPosition(
			button.rect).y);
}

int render_button(frame_t *frame, button_t *button)
{
	sfRenderStates *states = NULL;

	if (frame == NULL || button == NULL || button->enabled == false)
		return (1);
	states = init_render_states();
	if (button->status == 0 && button->texture_base != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_base, sfFalse);
	} else if (button->status == 1 && button->texture_hover != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_hover, sfFalse);
	} else {
		if (button->texture_clicked != NULL)
			sfRectangleShape_setTexture(button->rect,
			button->texture_clicked, sfFalse);
	}
	sfRenderWindow_drawRectangleShape(frame->window, button->rect, \
	states);
	free(states);
	return (0);
}
