/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "my_rpg.h"

text_info_t *create_text(char *font, char *text, sfVector2f pos, int size)
{
	text_info_t *text_info = malloc(sizeof(text_info_t));

	text_info->font = sfFont_createFromFile(font);
	text_info->text = sfText_create();
	text_info->enabled = true;
	text_info->id_name = NULL;
	if (text != NULL)
		sfText_setString(text_info->text, text);
	sfText_setPosition(text_info->text, pos);
	sfText_setColor(text_info->text, sfGreen);
	sfText_setCharacterSize(text_info->text, size);
	return (text_info);
}

int render_text(frame_t *frame, text_info_t *text_info)
{
	sfRenderStates *states = NULL;

	if (frame == NULL || text_info == NULL || text_info->enabled == false)
		return (1);
	states = init_render_states();
	if (states == NULL)
		return (0);
	sfText_setFont(text_info->text, text_info->font);
	sfRenderWindow_drawText(frame->window, text_info->text, states);
	free(states);
	return (1);
}
