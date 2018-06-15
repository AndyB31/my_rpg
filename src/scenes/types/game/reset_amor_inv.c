/*
** EPITECH PROJECT, 2018
** reset_armor_inv
** File description:
** reset_amor_inv
*/

#include "my_rpg.h"

static int update_armor_inv2(scene_t *scene, inv_t *inv, frame_t *f)
{
	list_t *tmp = NULL;
	item_t *item = NULL;

	tmp = get_list_by_name(&(scene->button_list), "boots");
	item = get_item_by_id(&(f->item_list), inv->boots);
	if (inv && inv->boots && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	tmp = get_list_by_name(&(scene->button_list), "shield");
	item = get_item_by_id(&(f->item_list), inv->shield);
	if (inv && inv->shield && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	tmp = get_list_by_name(&(scene->button_list), "gloves");
	item = get_item_by_id(&(f->item_list), inv->gloves);
	if (inv && inv->gloves && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	return (1);
}

static int update_armor_inv(scene_t *scene, inv_t *inv, frame_t *f)
{
	list_t *tmp = NULL;
	item_t *item = NULL;

	tmp = get_list_by_name(&(scene->button_list), "helmet");
	item = get_item_by_id(&(f->item_list), inv->helmet);
	if (inv && inv->helmet && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	tmp = get_list_by_name(&(scene->button_list), "chestplate");
	item = get_item_by_id(&(f->item_list), inv->chestplate);
	if (inv && inv->chestplate && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	tmp = get_list_by_name(&(scene->button_list), "sword");
	item = get_item_by_id(&(f->item_list), inv->weapon);
	if (inv && inv->weapon && tmp && tmp->button && item)
		set_bhc_texture(tmp->button, item->texture_path);
	return (update_armor_inv2(scene, inv, f));
}

int reset_armor_inv(scene_t *scene, inv_t *inv, frame_t *frame)
{
	list_t *tmp = NULL;

	tmp = get_list_by_name(&(scene->button_list), "helmet");
	set_bhc_texture(tmp->button, ASSET_N);
	tmp = get_list_by_name(&(scene->button_list), "chestplate");
	set_bhc_texture(tmp->button, ASSET_N);
	tmp = get_list_by_name(&(scene->button_list), "sword");
	set_bhc_texture(tmp->button, ASSET_N);
	tmp = get_list_by_name(&(scene->button_list), "boots");
	set_bhc_texture(tmp->button, ASSET_N);
	tmp = get_list_by_name(&(scene->button_list), "gloves");
	set_bhc_texture(tmp->button, ASSET_N);
	tmp = get_list_by_name(&(scene->button_list), "shield");
	set_bhc_texture(tmp->button, ASSET_N);
	update_armor_inv(scene, inv, frame);
	return (1);
}