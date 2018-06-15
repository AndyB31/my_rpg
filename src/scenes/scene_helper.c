/*
** EPITECH PROJECT, 2018
** scene_helper
** File description:
** scene_helper
*/
#include "my_rpg.h"

int should_play_music(scene_t *current, frame_t *frame)
{
	if (current->background_music != NULL) {
		frame->curr_sound = current->background_music;
		sfMusic_setLoop(current->background_music, sfTrue);
		sfMusic_play(current->background_music);
		if (frame->volume_stop == 1) {
			sfMusic_setVolume(current->background_music, \
			0);
		} else {
			sfMusic_setVolume(current->background_music, \
			frame->volume_level);
		}
	}
	return (1);
}

int render_all_sprites(list_t *list, frame_t *frame)
{
	list_t *sprites = list;

	while (sprites) {
		render_sprite(frame, sprites->sprite_inf);
		sprites = sprites->next;
	}
	return (1);
}

int render_all_buttons(list_t *list, frame_t *frame)
{
	list_t *buttons = list;

	while (buttons) {
		render_button(frame, buttons->button);
		buttons = buttons->next;
	}
	return (1);
}

int render_all_textfields(list_t *list, frame_t *frame)
{
	list_t *textfields = list;

	while (textfields) {
		render_textfield(frame, textfields->textfield);
		textfields = textfields->next;
	}
	return (1);
}

int render_all_texts(list_t *list, frame_t *frame)
{
	list_t *texts = list;

	while (texts) {
		render_text(frame, texts->text_inf);
		texts = texts->next;
	}
	return (1);
}
