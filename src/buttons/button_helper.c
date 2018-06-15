/*
** EPITECH PROJECT, 2018
** button_helper
** File description:
** button_helper
*/
#include "my_rpg.h"

int set_base_texture(button_t *button, char *path)
{
	sfTexture *texture = NULL;

	if (button == NULL)
		return (0);
	texture = sfTexture_createFromFile(path, NULL);
	if (texture == NULL)
		return (0);
	if (button->texture_base)
		sfTexture_destroy(button->texture_base);
	button->texture_base = texture;
	return (1);
}

int set_hover_texture(button_t *button, char *path)
{
	sfTexture *texture = NULL;

	if (button == NULL)
		return (0);
	texture = sfTexture_createFromFile(path, NULL);
	if (texture == NULL)
		return (0);
	if (button->texture_hover)
		sfTexture_destroy(button->texture_hover);
	button->texture_hover = texture;
	return (1);
}

int set_clicked_texture(button_t *button, char *path)
{
	sfTexture *texture = NULL;

	if (button == NULL)
		return (0);
	texture = sfTexture_createFromFile(path, NULL);
	if (texture == NULL)
		return (0);
	if (button->texture_clicked)
		sfTexture_destroy(button->texture_clicked);
	button->texture_clicked = texture;
	return (1);
}

int set_bhc_texture(button_t *button, char *path)
{
	set_base_texture(button, path);
	set_hover_texture(button, path);
	set_clicked_texture(button, path);
	return (1);
}