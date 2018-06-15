/*
** EPITECH PROJECT, 2018
** game_scene_event
** File description:
** game_scene_event
*/

#include "my_rpg.h"

void player_move(int direction, frame_t *frame)
{
	static int last_direction = 0;

	frame->player->sprite->vertical_state = direction;
	if (last_direction != direction)
		frame->player->sprite->current_state = 1;
	frame->player->sprite->curr_tick = \
	frame->player->sprite->tick_max + 1;
	last_direction = direction;
	close_chest(frame);
}

int modify_name_desc(char *id, char *button_id, scene_t *s, list_t *item)
{
	list_t *tmp = NULL;

	if (my_are_equals(id, button_id)) {
		tmp = get_list_by_name(&(s->text_list), "name");
		sfText_setString(tmp->text_inf->text, \
		read_value_file(PATH_ITEM_NAME, item->item_inf->id));
		tmp = get_list_by_name(&(s->text_list), "desc");
		sfText_setString(tmp->text_inf->text, \
		read_value_file(PATH_ITEM_DESC, item->item_inf->id));
		free(id);
		return (1);
	}
	free(id);
	return (0);
}

int browse_item(list_t *item, frame_t *frame, scene_t *s, button_t *button)
{
	char *id = NULL;
	item_t *item2 = NULL;

	while (item) {
		id = my_nbr_to_str(item->item_inf->slot_id);
		item2 = get_item_by_id(&(frame->item_list), \
		item->item_inf->id);
		if (item2 == NULL) {
			item = item->next;
			free(id);
			continue;
		}
		if (modify_name_desc(id, button->id_name, s, item) == 1)
			break;
		item = item->next;
	}
	return (1);
}

void show_info_inventory(int x, int y, frame_t *frame, button_t *button)
{
	inv_t *inv = open_player_inventory();
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	list_t *item = NULL;
	list_t *tmp = NULL;

	if (inv == NULL)
		return;
	tmp = get_list_by_name(&(s->text_list), "name");
	sfText_setString(tmp->text_inf->text, "");
	tmp = get_list_by_name(&(s->text_list), "desc");
	sfText_setString(tmp->text_inf->text, "");
	item = inv->head;
	browse_item(item, frame, s, button);
}
