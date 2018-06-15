/*
** EPITECH PROJECT, 2018
** change_inventory_status
** File description:
** change_inventory_status
*/

#include "my_rpg.h"

bool is_chest_open(bool change_status, bool set_status, bool new_status)
{
	static bool status = true;

	if (change_status == true)
		status = !status;
	else if (set_status == true)
		status = new_status;
	return (status);
}

int change_chest_status(frame_t *frame, scene_t *game, char *chest_id)
{
	list_t *tmp = NULL;
	char *id = NULL;
	bool status = is_chest_open(true, false, false);

	if (status == true)
		update_chest(frame, game, chest_id);
	for (int i = 21; i <= 55; i++) {
		id = my_nbr_to_str(i);
		tmp = get_list_by_name(&(game->button_list), id);
		free(id);
		if (tmp)
			tmp->button->enabled = status;
	}
	tmp = get_list_by_name(&(game->sprite_list), "chest");
	tmp->sprite_inf->enabled = status;
	return (0);
}