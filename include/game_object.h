/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** struct header
*/

#ifndef GAME_OBJ_H_
	#define GAME_OBJ_H_

#include "my.h"
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct item_s item_t;
typedef struct item_inf_s item_inf_t;

#include <scene.h>
/* les enum ce sont des idées ce sera peut-etre pas ça et
les structures sont incomplétes mais c'est pour commencer*/

enum item_type {
	WEAPON,
	HELMET,
	BOOTS,
	CHESTPLATE,
	GLOVES,
	SHIELD,
	POTION,
	FOOD,
	OTHER,
};

enum sort_type {
	WATER,
	FIRE,
	WIND,
	DIRT,
};

enum attribute_type {
	HEAL,
	PA,
	HP_ADD,
	PA_ADD,
	WATER_ADD,
	FIRE_ADD,
	WIND_ADD,
	DIRT_ADD
};


typedef struct attributes_s {
	int heal;
	int pa;
	int hp_add;
	int pa_add;
	int water;
	int fire;
	int wind;
	int dirt;
} attributes_t;

typedef struct item_s {
	char *id;
	enum item_type type;
	sfTexture *texture;
	char *texture_path;
	int stack_size;
	char *desc;
	char *name;
	attributes_t *attribute;
}item_t;

typedef struct item_inf_s {
	char *id;
	int nbr;
	int slot_id;
}item_inf_t;

typedef struct inventory_s {
	list_t *head;
	int size_max;
	char *id;
	char *helmet;
	char *chestplate;
	char *boots;
	char *gloves;
	char *weapon;
	char *shield;
}inv_t;

typedef struct spell_s {
	button_t *spell;
	sfMusic *use_sound;
	bool can_use;
	enum sort_type type;
	int pa_cost;
	int pa_remove;
	int pa_give;
	int bonus_time;
	int malus_time;
	int pv_cost;
	int pv_remove;
	int pv_give;
}spell_t;

typedef struct mob_s {
	bool round;
	int number_in_round;
	char *texture;
	sfSprite *sprite;
	int pv;
	int pv_max;
	int pa;
	int px_get;
}mob_t;

typedef struct player_s {
	int round;
	int number_in_round;
	inv_t *inventory;
	sfVector2i pos;
	sprite_info_t *sprite;
	int dirt;
	int wind;
	int fire;
	int where;
	int where_old;
	int water;
	int magic;
	int xp;
	int lvl;
	int pa;
	int pv;
	int pa_max;
	int pv_max;
}player_t;

#endif /* !STRUCT_H_ */
