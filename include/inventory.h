/*
** EPITECH PROJECT, 2018
** inventory
** File description:
** inventory
*/

#ifndef INVENTORY_H_
	#define INVENTORY_H_

#include "my_rpg.h"

void click_action_inventory(int x, int y, frame_t *frame, button_t *button);
void show_info_inventory(int x, int y, frame_t *frame, button_t *button);
void event_init(frame_t *frame, scene_t *scene);
sfRenderStates *init_render_states(void);
int free_inventory(inv_t *inv);
void bag_button_action(int x, int y, frame_t *frame, button_t *button);
void inventory_key_press_event(sfKeyEvent event, frame_t *frame);
item_inf_t *get_item_inv_slot(inv_t *inv, int id);
item_inf_t *get_item_inv_id(inv_t *inv, char *item_name);
char *read_value_file(char *path, char *key);
int free_item(item_t *item);
int free_item_inf(item_inf_t *item_inf);
int change_inventory_status(frame_t *frame, scene_t *game);
inv_t *read_inventory(char *id);
int modify_name_desc(char *id, char *button_id, scene_t *s, list_t *item);
int browse_item(list_t *item, frame_t *frame, scene_t *s, button_t *button);
void show_info_inventory(int x, int y, frame_t *frame, button_t *button);
int update_inventory(frame_t *frame, scene_t *scene);
int init_texts_inventory(scene_t *game);
int set_equipment(inv_t *inv, item_t *item, enum item_type type, bool force);
int set_shield(inv_t *inv, item_t *item, bool force);
int set_weapon(inv_t *inv, item_t *item, bool force);
int set_helmet(inv_t *inv, item_t *item, bool force);
int set_boots(inv_t *inv, item_t *item, bool force);
int set_chestplate(inv_t *inv, item_t *item, bool force);
int set_gloves(inv_t *inv, item_t *item, bool force);
int reset_armor_inv(scene_t *scene, inv_t *inv, frame_t *frame);
item_inf_t *init_item_inf(char *id, int stack_size, int slot_id);
item_inf_t *add_item_to_inv(inv_t *inv, char *id, int nbr, frame_t *f);
item_inf_t *add_item_inf_to_list(inv_t *inv, item_inf_t *inf);
int get_slot_id(inv_t *inv);
item_inf_t *can_add_item(inv_t *inv, char *id, int nbr, frame_t *f);
void click_action_armor(int x, int y, frame_t *frame, button_t *button);
int delete_item(inv_t *inv, item_inf_t *id, int nbr, int slot_id);
int delete_element(list_t **head, int id);
list_t *get_list_by_id(list_t **head, int id);
int remove_equipment(inv_t *inv, enum item_type type);
int set_bhc_texture(button_t *button, char *path);
int init_chest_buttons(scene_t *game);
void click_action_chest_l(int x, int y, frame_t *frame, button_t *button);
void click_action_chest_r(int x, int y, frame_t *frame, button_t *button);
void show_info_chest(int x, int y, frame_t *frame, button_t *button);
int change_chest_status(frame_t *frame, scene_t *game, char *chest_id);
int update_chest(frame_t *frame, scene_t *game, char *id);
inv_t *open_player_inventory(void);
int init_intro_scene(list_t **scene_list, frame_t *frame);
void intro_scene_tick(frame_t *frame, scene_t *scene);
void intro_scene_tick2(frame_t *frame, scene_t *scene);
char *set_str_to(char *src, char *new_str);
void cutscene_key_press_event(sfKeyEvent event, frame_t *frame);
void option_key_press_event(sfKeyEvent event, frame_t *frame);
void game_init_event(frame_t *frame, scene_t *scene);
void open_cutscene(frame_t *frame, char *id);
int close_chest(frame_t *frame);

#endif /* !INVENTORY_H_ */
