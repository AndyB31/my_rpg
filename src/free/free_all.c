/*
** EPITECH PROJECT, 2017
** free_all
** File description:
** free_all
*/
#include "my_rpg.h"

int free_button(button_t *button)
{
	if (button == NULL)
		return (0);
	if (button->texture_base)
		sfTexture_destroy(button->texture_base);
	if (button->texture_clicked)
		sfTexture_destroy(button->texture_clicked);
	if (button->texture_hover)
		sfTexture_destroy(button->texture_hover);
	if (button->click_sound)
		sfMusic_destroy(button->click_sound);
	if (button->rect)
		sfRectangleShape_destroy(button->rect);
	if (button->id_name)
		free(button->id_name);
	free(button);
	return (1);
}

int free_scene(scene_t *scene)
{
	if (scene == NULL)
		return (0);
	if (scene->background_music)
		sfMusic_destroy(scene->background_music);
	if (scene->sprite_list)
		free_list(scene->sprite_list);
	if (scene->text_list)
		free_list(scene->text_list);
	if (scene->button_list)
		free_list(scene->button_list);
	if (scene->textfield_list)
		free_list(scene->textfield_list);
	free(scene);
	return (1);
}

int free_textfield(textfield_t *textfield)
{
	if (textfield == NULL)
		return (1);
	if (textfield->id_name)
		free(textfield->id_name);
	if (textfield->rect)
		sfRectangleShape_destroy(textfield->rect);
	if (textfield->text_info)
		free_text_inf(textfield->text_info);
	if (textfield->texture)
		sfTexture_destroy(textfield->texture);
	free(textfield);
	return (1);
}

int free_list(list_t *head)
{
	list_t *element = NULL;

	while (head) {
		element = head;
		free_button(element->button);
		free_scene(element->scene);
		free_sprite_inf(element->sprite_inf);
		free_text_inf(element->text_inf);
		free_item(element->item);
		free_item_inf(element->item_inf);
		free_textfield(element->textfield);
		if (element->id_name)
			free(element->id_name);
		element->id_name = NULL;
		head = head->next;
		if (element)
			free(element);
	}
	return (1);
}

int free_frame(frame_t *frame)
{
	inv_t *inv = open_player_inventory();

	write_player(frame->player);
	write_inventory(inv);
	free_inventory(inv);
	free_player(frame->player);
	if (frame == NULL)
		return (0);
	sfClock_destroy(frame->clock);
	free_list(frame->scene);
	if (frame->window)
		sfRenderWindow_destroy(frame->window);
	free_list(frame->item_list);
	free(frame);
	return (1);
}
