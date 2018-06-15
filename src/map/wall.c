/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/
#include "my_rpg.h"

char *copy_in_buffer_wall(map_t *map, char *filepath)
{
	char *temp = malloc(sizeof(char) * 2);
	int i = 0;
	int tmp = open(filepath, O_RDONLY);
	char *buffer = NULL;

	for (i = 0; read(tmp, temp, 1); i++) ;
	i++;
	close(tmp);
	tmp = open(filepath, O_RDONLY);
	map->wall = malloc((sizeof(gameobj_t) * i));
	buffer = malloc((sizeof(char) * i));
	read(tmp, buffer, i);
	buffer[i] = '\0';
	close(tmp);
	return buffer;
}

int display_wall (frame_t *frame)
{
	sfVector2f scale = {3, 3};
	sfVector2f scale2 = {1.5, 1.5};
	frame->player->sprite->scale = scale2;
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++)
	{
		if (frame->map[where].wall[i].id != 0) {
			sfIntRect rec = {(((frame->map[where].wall[i].id % 32)
			- 1) * 8), (((frame->map[where].wall[i].id / 32)) * 8)
			, 8, 8};
			frame->map[where].wall[i].sprite->scale = scale;
			render_sprite2(frame,
			frame->map[where].wall[i].sprite, rec);
		}
	}
	return (0);
}

void stock_wall2(map_t *map, char **all_id, int temp)
{
	sfVector2i size = {24, 24};

	map->wall[temp].id = my_get_nbr(all_id[temp]);
	if (map->wall[temp].id != 0) {
		map->wall[temp].sprite = create_sprite(0, size,
		"./assets/terrain/CB-Temple-B.png");
		sprite_set_pos(map->wall[temp].sprite, map->wall[temp].pos.x,
		map->wall[temp].pos.y);
	} else
		map->wall[temp].sprite = NULL;
}

void stock_wall(map_t *map, char *wall)
{
	int fd = open (wall, O_RDONLY);
	char *buffer = copy_in_buffer_wall(map, wall);
	int posx = 0;
	int posy = 0;
	int temp = 0;
	char **all_id = my_str_to_word_array(buffer);

	for (int i = 0; i < 55; posy += 24, i++) {
		for (int j = 0; j < 55; posx += 24, temp++, j++) {
			map->wall[temp].pos.x = posx;
			map->wall[temp].pos.y = posy;
			stock_wall2(map, all_id, temp);
		}
		posx = 0;
	}
	map->wall[temp].id = -1;
	close(fd);
}
