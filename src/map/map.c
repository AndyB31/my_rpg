/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/
#include "my_rpg.h"

int display_map (frame_t *frame)
{
	display_floor(frame);
	display_wall(frame);
	sprite_set_pos(frame->player->sprite, frame->player->pos.x,
	frame->player->pos.y);
	render_sprite(frame, frame->player->sprite);
	display_behind(frame);

	return (0);
}

void init_map(map_t *map, char *flor, char *wall, char *behind)
{
	stock_map(map, flor);
	stock_wall(map, wall);
	stock_behind(map, behind);
}

map_t copy_map (char *flor, char *wall, char *behind)
{
	map_t *temp = malloc(sizeof(map_t));
	map_t map;

	init_map(temp, flor, wall, behind);
	map.flor = temp->flor;
	map.wall = temp->wall;
	map.behind = temp->behind;
	free(temp);
	return (map);
}

void init_all_maps(map_t *map)
{
	map[0] = copy_map("./data/m/1_f", "./data/m/1_w", "./data/m/1_b");
	map[1] = copy_map("./data/m/2_f", "./data/m/2_w", "./data/m/2_b");
	map[2] = copy_map("./data/m/3_f", "./data/m/3_w", "./data/m/3_b");
	map[3] = copy_map("./data/m/4_f", "./data/m/4_w", "./data/m/4_b");
	map[4] = copy_map("./data/m/5_f", "./data/m/5_w", "./data/m/5_b");
	map[5] = copy_map("./data/m/6_f", "./data/m/6_w", "./data/m/6_b");
	map[6] = copy_map("./data/m/7_f", "./data/m/7_w", "./data/m/7_b");
	map[7] = copy_map("./data/m/8_f", "./data/m/8_w", "./data/m/8_b");
	map[8] = copy_map("./data/m/9_f", "./data/m/9_w", "./data/m/9_b");
	map[9] = copy_map("./data/m/10_f", "./data/m/10_w", "./data/m/10_b");
	map[10] = copy_map("./data/m/11_f", "./data/m/11_w", "./data/m/11_b");
	map[11] = copy_map("./data/m/12_f", "./data/m/12_w", "./data/m/12_b");
	map[12] = copy_map("./data/m/13_f", "./data/m/13_w", "./data/m/13_b");
	map[13] = copy_map("./data/m/14_f", "./data/m/14_w", "./data/m/14_b");
}
