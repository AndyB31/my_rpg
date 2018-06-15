/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
	#define MY_RPG_H_

#include "macro.h"
#include "game_object.h"
#include "scene.h"
#include "my.h"
#include "inventory.h"
#include "fight.h"

int set_base_texture(button_t *button, char *path);
int set_hover_texture(button_t *button, char *path);
int set_clicked_texture(button_t *button, char *path);
button_t *create_button(sfVector2f position, sfVector2f size);
int is_mouse_on_button(button_t button, sfVector2f clickPosition);
int render_button(frame_t *frame, button_t *button);
void key_manager(sfKeyEvent event, frame_t *frame);
void mouse_button_move_manager(sfMouseMoveEvent event, frame_t *frame);
void mouse_button_released_manager(sfMouseButtonEvent event, frame_t *frame);
void mouse_button_pressed_manager(sfMouseButtonEvent event, frame_t *frame);
int check_music(list_t *curr_button, frame_t *frame);
void event_manager(sfEvent event, frame_t *frame);
int free_frame(frame_t *frame);
int free_list(list_t *head);
int free_scene(scene_t *scene);
int free_button(button_t *button);
int free_sprite_inf(sprite_info_t *sprite_inf);
int free_text_inf(text_info_t *text_info);
int add_textfield(list_t **head, textfield_t *textfield, char *id_name);
list_t *create_list(void);
int init_main_menu(list_t **scene_list, frame_t *frame);
int render_all_texts(list_t *list, frame_t *frame);
int render_all_textfields(list_t *list, frame_t *frame);
int render_all_buttons(list_t *list, frame_t *frame);
int render_all_sprites(list_t *list, frame_t *frame);
int should_play_music(scene_t *current, frame_t *frame);
scene_t *create_scene(scene_type_t type);
scene_t *get_scene_by_type(list_t **list, scene_type_t type);
int render_scene(frame_t *frame, list_t **scene_list, scene_type_t type);
int set_scene_to(frame_t *frame, scene_type_t type, bool stop_music);
void init_scenes(list_t **scene_list, frame_t *frame);
sprite_info_t *create_sprite(int total_states, sfVector2i size, \
const char *texture_path);
int render_sprite(frame_t *frame, sprite_info_t *sprite_inf);
int sprite_set_speed(sprite_info_t *sprite_inf, float x, float y);
int sprite_set_scale(sprite_info_t *sprite_inf, float x, float y);
int sprite_set_pos(sprite_info_t *sprite_inf, float x, float y);
int render_textfield(frame_t *frame, textfield_t *textfield);
void fill_textfield(sfTextEvent event, scene_t *scene);
void apply_backspace(sfTextEvent event, scene_t *scene);
textfield_t *create_textfield(sfVector2f position, sfVector2f size, \
char *font_path);
text_info_t *create_text(char *font, char *text, sfVector2f pos, int size);
int render_text(frame_t *frame, text_info_t *text_info);
int is_char_alphanumeric(char c);
void display_frame(int width, int height);
void game_loop(frame_t *frame);
frame_t *init(int width, int height);
int add_item(list_t **head, item_t *item);
attributes_t *create_attribute(void);
item_t *create_item(char *id, enum item_type type, int stack_size, \
char *texture);
int register_items(frame_t *frame);
int set_attribute(item_t *item, enum attribute_type type, \
int value);
int get_list_length(list_t **head);
int add_button(list_t **head, button_t *b, char *id_name);
int add_sprite_inf(list_t **head, sprite_info_t *sprite_inf, char *id_name);
int add_scene(list_t **head, scene_t *scene);
int add_text_inf(list_t **head, text_info_t *text_inf, char *id_name);
bool is_file_in_dir(char *name, char *dir_path);
inv_t *create_inventory(char *id, int size_max);
int write_inventory(inv_t *inv);
int register_inventory(frame_t *frame);
item_inf_t *get_item_in_env(inv_t *inv, char *item_name);
int get_nbr_of_items(inv_t *inv, char *item_name);
bool is_inventory_contains(inv_t *inv, char *item_name);
int init_main_menu_scene(list_t **scene_list, frame_t *frame);
int init_game_scene(list_t **scene_list, frame_t *frame);
void main_menu_play_button(int x, int y, frame_t *frame, button_t *button);
void main_menu_exit_button(int x, int y, frame_t *frame, button_t *button);
void init_play_button(scene_t *scene);
void init_option_button(scene_t *scene, int x, int y);
void init_exit_button(scene_t *scene, int x, int y);
int open_inventory(frame_t *frame, char *inv_id);
void game_key_press_event(sfKeyEvent event, frame_t *frame);
int init_main_menu_scene(list_t **scene_list, frame_t *frame);
item_t *get_item_by_id(list_t **head, char *id);
list_t *get_list_by_name(list_t **head, char *id_name);
void game_plus_button(int x, int y, frame_t *frame, button_t *button);
void click_action_inventory(int x, int y, frame_t *frame, button_t *button);
void change_texture(button_t *button);
void change_status_button(button_t *button);
void change_status_sprite(sprite_info_t *sprite);
char *bar_from_number(int x);
void update_fight(frame_t *frame, scene_t *scene);
void init_menu_button(scene_t *main_menu, int x, int y);
void init_up_button(scene_t *option);
void main_menu_option_button(int x, int y, frame_t *frame, button_t *button);
int init_option_scene(list_t **scene_list, frame_t *frame);
void menu_button_action(int x, int y, frame_t *frame, button_t *button);
void gear_button_action(int x, int y, frame_t *frame, button_t *button);
void resume_button_action(int x, int y, frame_t *frame, button_t *button);
int open_pause_menu(frame_t *frame);
void pause_key_press_event(sfKeyEvent event, frame_t *frame);
void init_player(frame_t *frame);
int init_game_scene_buttons(scene_t *game);
int init_game_scene_sprites(scene_t *game);
int display_dial(scene_t *game, char *path, int i);
int run_dialogues(frame_t *frame, scene_t *game);
int update_game(frame_t *frame, scene_t *game);
int destroy_dialogues(frame_t *frame, scene_t *game);
int init_pause_scene(list_t **scene_list, frame_t *frame);
int init_quest_scene(list_t **scene_list, frame_t *frame);
void quest_key_press_event(sfKeyEvent event, frame_t *frame);
void init_resume_button(scene_t *main_menu, int x, int y);
void book_button_action(int x, int y, frame_t *frame, button_t *button);
int run_particuls(frame_t *frame, scene_t *game);
void init_plus_button(scene_t *game);
void init_book_button(scene_t *game);
void init_bag_button(scene_t *game);
void init_gear_button(scene_t *game);
void init_tree_button(scene_t *game);
void init_menu_button(scene_t *option, int x, int y);
void init_up_button(scene_t *option);
void init_down_button(scene_t *option);
void init_mute_button(scene_t *option);
int init_texts_dial(scene_t *game);
void init_dna_button(scene_t *game);
int update_dialogues(frame_t *frame, scene_t *game);
int set_equipement(inv_t *inv, item_t *item, enum item_type type, bool force);
void option_mute_button(int x, int y, frame_t *frame, button_t *button);
void option_down_button(int x, int y, frame_t *frame, button_t *button);
void option_up_button(int x, int y, frame_t *frame, button_t *button);
void update_walk(frame_t *frame, scene_t *scene);
sprite_info_t *create_sprite2(int total_states, sfVector2i size, \
const char *texture_path);
player_t *create_player(void);
int write_player(player_t *player);
player_t *read_player(void);
int player_manager(frame_t *frame);
int init_game_lvl_sprites(scene_t *game);
int init_game_lvl_heart(scene_t *game);
int init_game_lvl_power(scene_t *game);
int init_game_lvl_xp(scene_t *game);
int update_lvl(frame_t *frame, scene_t *game);
int disable_xp(scene_t *game);
int disable_powey(scene_t *game);
int disable_heart(scene_t *game);
int update_heart(frame_t *frame, scene_t *game);
int update_power(frame_t *frame, scene_t *game);
int update_xp(frame_t *frame, scene_t *game);
char *copy_in_buffer_behind(map_t *map, char *filepath);
char *copy_in_buffer_floor(map_t *map, char *filepath);
char *copy_in_buffer_wall(map_t *map, char *filepath);
int display_behind (frame_t *frame);
void stock_behind2(map_t *map, char **all_id, int temp);
void stock_behind(map_t *map, char *behind);
void init_map(map_t *map, char *flor, char *wall, char *behind);
int display_map (frame_t *frame);
int render_sprite2(frame_t *frame, sprite_info_t *sprite_inf, sfIntRect rec);
void stock_map(map_t *map, char *flor);
void stock_map2(map_t *map, char **all_id, int temp);
int display_floor (frame_t *frame);
int display_wall (frame_t *frame);
void stock_wall2(map_t *map, char **all_id, int temp);
void stock_wall(map_t *map, char *wall);
void move_player(frame_t *frame);
int check_interaction(frame_t *frame);
int run_particuls(frame_t *frame, scene_t *scene);
int close_inventory(frame_t *frame);
bool is_inv_open(bool change_status, bool set_status, bool new_status);
int open_chest(frame_t *frame, char *inv_id);
int update_game(frame_t *frame, scene_t *game);
void player_move(int direction, frame_t *frame);
int init_main_menu_sprite(scene_t *main_menu);
bool is_chest_open(bool change_status, bool set_status, bool new_status);
int init_cutscenes_scene(list_t **scene_list, frame_t *frame);
int free_player(player_t *player);
map_t copy_map (char *flor, char *wall, char *behind);
int check_teleport(frame_t *frame);
int check_new_pos(frame_t *frame);
void move_player(frame_t *frame);
int check_coli_up(frame_t *frame);
int check_coli_down(frame_t *frame);
int check_coli_left(frame_t *frame);
int check_coli_right(frame_t *frame);
#endif /* !MY_RPG_H_ */
