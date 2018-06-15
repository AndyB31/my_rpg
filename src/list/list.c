/*
** EPITECH PROJECT, 2017
** list
** File description:
** list
*/
#include "my_rpg.h"

int add_button(list_t **head, button_t *b, char *id_name)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (1);
	curr = *head;
	element->button = b;
	element->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	element->id_name = my_strcpy(element->id_name, id_name);
	b->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	b->id_name = my_strcpy(b->id_name, id_name);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (0);
}

int add_sprite_inf(list_t **head, sprite_info_t *sprite_inf, char *id_name)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (1);
	curr = *head;
	element->sprite_inf = sprite_inf;
	element->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	element->id_name = my_strcpy(element->id_name, id_name);
	sprite_inf->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	sprite_inf->id_name = my_strcpy(sprite_inf->id_name, id_name);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (0);
}

int add_scene(list_t **head, scene_t *scene)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (1);
	curr = *head;
	element->scene = scene;
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (0);
}

int add_textfield(list_t **head, textfield_t *textfield, char *id_name)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (1);
	curr = *head;
	element->textfield = textfield;
	element->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	element->id_name = my_strcpy(element->id_name, id_name);
	textfield->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	textfield->id_name = my_strcpy(textfield->id_name, id_name);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (0);
}

int add_text_inf(list_t **head, text_info_t *text_inf, char *id_name)
{
	list_t *element = create_list();
	list_t *curr = NULL;

	if (element == NULL)
		return (0);
	curr = *head;
	element->text_inf = text_inf;
	element->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	element->id_name = my_strcpy(element->id_name, id_name);
	text_inf->id_name = malloc((my_strlen(id_name) + 1) * sizeof(char));
	text_inf->id_name = my_strcpy(text_inf->id_name, id_name);
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		element->id = curr->id + 1;
		curr->next = element;
	}
	return (0);
}
