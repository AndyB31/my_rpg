/*
** EPITECH PROJECT, 2018
** change_inventory_status
** File description:
** change_inventory_status
*/

#include "my_rpg.h"

bool is_inv_open(bool change_status, bool set_status, bool new_status)
{
	static bool status = true;

	if (change_status == true)
		status = !status;
	else if (set_status == true)
		status = new_status;
	return (status);
}

static int set_inventory_status3(scene_t *game, bool status)
{
	list_t *tmp = NULL;
	char *id = NULL;

	for (int i = 0; i < 14; i++) {
		id = my_nbr_to_str(66 + i);
		tmp = get_list_by_name(&(game->text_list), id);
		if (tmp == NULL)
			continue;
		tmp->text_inf->enabled = status;
		free(id);
	}
	tmp = get_list_by_name(&(game->text_list), "name");
	tmp->text_inf->enabled = status;
	tmp = get_list_by_name(&(game->text_list), "desc");
	tmp->text_inf->enabled = status;
	return (0);
}

static int set_inventory_status2(scene_t *game, bool status)
{
	list_t *tmp = NULL;

	tmp = get_list_by_name(&(game->button_list), "helmet");
	tmp->button->enabled = status;
	tmp = get_list_by_name(&(game->button_list), "chestplate");
	tmp->button->enabled = status;
	tmp = get_list_by_name(&(game->button_list), "sword");
	tmp->button->enabled = status;
	tmp = get_list_by_name(&(game->button_list), "boots");
	tmp->button->enabled = status;
	tmp = get_list_by_name(&(game->button_list), "gloves");
	tmp->button->enabled = status;
	tmp = get_list_by_name(&(game->button_list), "shield");
	tmp->button->enabled = status;
	set_inventory_status3(game, status);
	return (1);
}

int change_inventory_status(frame_t *frame, scene_t *game)
{
	list_t *tmp = NULL;
	char *id = NULL;
	bool status = is_inv_open(true, false, false);

	close_chest(frame);
	if (status == true)
		update_inventory(frame, game);
	for (int i = 1; i <= 14; i++) {
		id = my_nbr_to_str(i);
		tmp = get_list_by_name(&(game->button_list), id);
		tmp->button->enabled = status;
		free(id);
	}
	tmp = get_list_by_name(&(game->sprite_list), "inv");
	tmp->sprite_inf->enabled = status;
	return (set_inventory_status2(game, status));
}