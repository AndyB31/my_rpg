/*
** EPITECH PROJECT, 2018
** my_struct
** File description:
** my_struct
*/

#ifndef SCENE_H_
	#define SCENE_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game_object.h"

typedef enum scene_type_e
{
	MAIN_MENU,
	GAME,
	FIGHT,
	SEARCH_SAVE,
	QUEST,
	OPTION,
	PAUSE,
	SAVEMAP,
	LOADMAP,
	INVENTORY,
	INTRO,
	WIN,
	LOSE,
	CUTSCENE
}scene_type_t;

typedef struct textfield_s textfield_t;
typedef struct vertex_s vertex_t;
typedef struct frame_s frame_t;
typedef struct scene_s scene_t;
typedef struct button_s button_t;
typedef struct sprite_info_s sprite_info_t;
typedef struct text_info_s text_info_t;
typedef struct list_s list_t;
typedef struct player_s player_t;
typedef struct mob_s mob_t;

struct sprite_info_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2i size;
	sfVector2f pos;
	sfVector2f scale;
	sfVector2f speed;
	int total_states;
	int current_state;
	int is_init;
	bool enabled;
	char *id_name;
	int tick_max;
	int curr_tick;
	int vertical_state;
};

struct textfield_s
{
	sfRectangleShape *rect;
	text_info_t *text_info;
	sfTexture *texture;
	int max_lenght;
	int is_focus;
	bool enabled;
	char *id_name;
};

struct button_s
{
	sfRectangleShape *rect;
	sfTexture *texture_base;
	sfTexture *texture_hover;
	sfTexture *texture_clicked;
	void (*click_action)(int x, int y, frame_t *frame, button_t *button);
	void (*hover_action)(int x, int y, frame_t *frame, button_t *button);
	sfMusic *click_sound;
	int status;
	int texture_status;
	bool enabled;
	char *id_name;
};

struct scene_s
{
	scene_type_t type;
	list_t *button_list;
	list_t *sprite_list;
	list_t *text_list;
	list_t *textfield_list;
	sfMusic *background_music;
	void (*event_key_pressed)(sfKeyEvent event, frame_t *frame);
	void (*event_mouse_button_pressed)(sfMouseButtonEvent event, \
	frame_t *frame);
	void (*event_mouse_button_released)(sfMouseButtonEvent event, \
	frame_t *frame);
	void (*event_mouse_moved)(sfMouseMoveEvent event, frame_t *frame);
	void (*event_mouse_wheel_scroll)(sfMouseWheelScrollEvent event, \
	frame_t *frame);
	void (*event_tick)(frame_t *frame, scene_t *scene);
	void (*event_init)(frame_t *frame, scene_t *scene);
	void (*event_init_post)(frame_t *frame, scene_t *scene);
	int current_tick;
};

struct text_info_s
{
	sfText *text;
	sfFont *font;
	bool enabled;
	char *id_name;
};

struct list_s
{
	int id;
	char *id_name;
	button_t *button;
	sprite_info_t *sprite_inf;
	scene_t *scene;
	text_info_t *text_inf;
	textfield_t *textfield;
	item_t *item;
	item_inf_t *item_inf;
	list_t *next;
};

typedef struct game_object_s {
	sfVector2f pos;
	sprite_info_t *sprite;
	int id;
}gameobj_t;

typedef struct map_s {
	gameobj_t *wall;
	gameobj_t *flor;
	gameobj_t *behind;
}map_t;

struct frame_s
{
	int width;
	int height;
	list_t *scene;
	map_t *map;
	scene_type_t curent_scene;
	scene_type_t last_scene;
	sfEvent event;
	sfRenderWindow *window;
	sfClock *clock;
	int volume_stop;
	int volume_level;
	sfMusic *curr_sound;
	player_t *player;
	mob_t **mob;
	int selected_spell;
	int current_spell;
	list_t *item_list;
	char *path;
	int dial_nbr;
	char *curr_chest;
	char *cutscene;
	char *curr_cutscene;
	int is_new_player;
};

#endif /* !MY_STRUCT_H_ */
