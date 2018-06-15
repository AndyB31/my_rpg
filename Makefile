##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## This makefile compiles our sources files
##

NAME			=	my_rpg

SRC			=	./src/main.c \
				./src/frame.c \
				./src/bar_from_number.c

SRC_BUTTONS		=	./src/buttons/button_manager.c \
				./src/buttons/button_helper.c

SRC_EVENTS		=	./src/events/event_manager.c \
				./src/events/types/key_manager.c \
				./src/events/types/mouse_button_manager.c

SRC_FREE		=	./src/free/free_all.c \
				./src/free/free_all2.c

SRC_LIST		=	./src/list/list.c \
				./src/list/create_list.c \
				./src/list/get_list_length.c \
				./src/list/get_list_by_name.c \
				./src/list/delete_list.c

SRC_SCENES		=	./src/scenes/scene_manager.c \
				./src/scenes/scene_helper.c

SRC_SCENE_MAIN_MENU	=	./src/scenes/types/main_menu/main_menu_actions.c \
				./src/scenes/types/main_menu/main_menu_buttons.c \
				./src/scenes/types/main_menu/main_menu_scene.c

SRC_SCENE_OPTION	=	./src/scenes/types/option/option_actions.c \
				./src/scenes/types/option/option_buttons.c \
				./src/scenes/types/option/option_scene.c

SRC_SCENE_QUEST	=		./src/scenes/types/quest/quest_scene.c \
				./src/scenes/types/quest/particuls/particuls.c \
				./src/scenes/types/quest/quest_events.c

SRC_SCENE_PAUSE	=		./src/scenes/types/pause/pause_actions.c \
				./src/scenes/types/pause/pause_buttons.c \
				./src/scenes/types/pause/open_pause.c \
				./src/scenes/types/pause/pause_events.c \
				./src/scenes/types/pause/pause_scene.c

SRC_SCENE_GAME		=	./src/scenes/types/game/game_scene_events.c \
				./src/scenes/types/game/game_scene_events_2.c \
				./src/scenes/types/game/game_buttons.c \
				./src/scenes/types/game/game_actions.c \
				./src/scenes/types/game/game_actions_2.c \
				./src/scenes/types/game/game_scene.c \
				./src/scenes/types/game/game_buttons_2.c \
				./src/scenes/types/game/init_game_object.c \
				./src/scenes/types/game/lvl/init_lvl_sprites.c \
				./src/scenes/types/game/lvl/disable_lvl.c \
				./src/scenes/types/game/lvl/update_lvl.c \
				./src/scenes/types/game/inventory/game_inventory_overlay.c \
				./src/scenes/types/game/init_texts_inventory.c \
				./src/scenes/types/game/dialogues/init_texts_dial.c \
				./src/scenes/types/game/dialogues/run_dialogues.c \
				./src/scenes/types/game/inventory/change_inventory_status.c \
				./src/scenes/types/game/inventory/inventory_actions.c \
				./src/scenes/types/game/reset_amor_inv.c \
				./src/scenes/types/game/chest/init_chest_buttons.c \
				./src/scenes/types/game/chest/chest_actions.c \
				./src/scenes/types/game/chest/change_chest_status.c \
				./src/scenes/types/game/chest/update_chest.c \
				./src/scenes/types/game/check_interaction.c \
				./src/scenes/types/game/inventory/close_inventory.c

SRC_SCENE_FIGHT		=	./src/scenes/types/fight/fight_utils.c \
				./src/scenes/types/fight/init_scene_fight.c \
				./src/scenes/types/fight/init_scene_fight2.c \
				./src/scenes/types/fight/init_scene_fight3.c \
				./src/scenes/types/fight/init_scene_fight4.c \
				./src/scenes/types/fight/update_fight.c \
				./src/scenes/types/fight/spell_effect.c \
				./src/scenes/types/win_lose/init_win_scene.c \
				./src/scenes/types/win_lose/init_lose_scene.c \
				./src/scenes/types/fight/spell_effect2.c

SRC_SCENE_INTRO		=	./src/scenes/types/intro/init_intro_scene.c

SRC_SCENE_CUTSCENE	=	./src/scenes/types/cutscenes/init_cutscenes_scene.c \
				./src/scenes/types/cutscenes/open_cutscene.c \
				./src/scenes/types/cutscenes/cutscenes_events.c

SRC_SPRITES		=	./src/sprites/sprites_manager.c \
				./src/sprites/sprites_manager2.c \
				./src/sprites/render_sprite.c

SRC_TEXTFIELD		=	./src/textfield/textfield_manager.c

SRC_TEXTS		=	./src/texts/texts_manager.c

SRC_UTILS		=	./src/utils/is_char_alphanumeric.c \
				./src/utils/init_render_states.c \
				./src/utils/set_str_to.c

SRC_ITEMS		=	./src/items/add_item.c \
				./src/items/create_attribute.c \
				./src/items/create_item.c \
				./src/items/item_manager.c \
				./src/items/set_attribute.c \
				./src/items/get_item_by_id.c \
				./src/items/init_item_inf.c \
				./src/items/delete_item.c

SRC_MAP			=	./src/map/map.c \
				./src/map/behind.c \
				./src/map/wall.c \
				./src/map/floor.c

SRC_DATA		=	./src/data/read_str_fd.c \
				./src/data/write_str_fd.c \
				./src/data/read_nbr_fd.c \
				./src/data/write_nbr_fd.c

SRC_INVENTORY		=	./src/inventory/add_item_to_inv.c \
				./src/inventory/add_item_to_inv2.c \
				./src/inventory/create_inventory.c \
				./src/inventory/inventory_manager.c \
				./src/inventory/read_inventory.c \
				./src/inventory/write_inventory.c \
				./src/inventory/get_item_in_env.c \
				./src/inventory/get_nbr_of_items.c \
				./src/inventory/is_inventory_contains.c \
				./src/inventory/open_chest.c \
				./src/inventory/set_armor.c \
				./src/inventory/set_equipment.c \
				./src/inventory/remove_equipment.c \
				./src/inventory/get_inv_carac_fw.c \
				./src/inventory/get_inv_carac_hp.c \
				./src/inventory/get_inv_carac_wd.c \
				./src/inventory/open_player_inventory.c \
				./src/inventory/close_chest.c

SRC_PARSER		=	./src/parser/read_value_file.c

SRC_PLAYER		=	./src/player/init_player.c \
				./src/player/read_player.c \
				./src/player/write_player.c \
				./src/player/move_player.c \
				./src/player/collision.c \
				./src/player/check_boss.c \
				./src/player/free_player.c

OBJ			=	$(SRC:.c=.o) $(SRC_BUTTONS:.c=.o)  \
				$(SRC_EVENTS:.c=.o) $(SRC_FREE:.c=.o)  \
				$(SRC_LIST:.c=.o) $(SRC_TEXTFIELD:.c=.o) \
				$(SRC_SCENES:.c=.o) $(SRC_SPRITES:.c=.o) \
				$(SRC_TEXTS:.c=.o) $(SRC_UTILS:.c=.o) \
				$(SRC_ITEMS:.c=.o) $(SRC_DATA:.c=.o) \
				$(SRC_INVENTORY:.c=.o) $(SRC_SCENE_MAIN_MENU:.c=.o) \
				$(SRC_PARSER:.c=.o) $(SRC_SCENE_GAME:.c=.o) \
				$(SRC_SCENE_FIGHT:.c=.o) $(SRC_SCENE_OPTION:.c=.o) \
				$(SRC_SCENE_PAUSE:.c=.o) $(SRC_SCENE_QUEST:.c=.o) \
				$(SRC_SCENE_INTRO:.c=.o) $(SRC_SCENE_CUTSCENE:.c=.o) \
				$(SRC_PLAYER:.c=.o) $(SRC_MAP:.c=.o)

FLAGS	=			-Wunused-parameter -Wall -W -Wextra -pedantic -L./lib -lmy -I./include/ -lm

all:	$(NAME)

valgrind:
	valgrind --leak-check=yes --show-reachable=yes -v ./$(NAME)

search:
	grep "my_putstr" $(SRC) $(SRC_BUTTONS)  \
			$(SRC_EVENTS) $(SRC_FREE)  \
			$(SRC_LIST) $(SRC_TEXTFIELD) \
			$(SRC_SCENES) $(SRC_SPRITES) \
			$(SRC_TEXTS) $(SRC_UTILS) \
			$(SRC_ITEMS) $(SRC_DATA) \
			$(SRC_INVENTORY) $(SRC_SCENE_MAIN_MENU) \
			$(SRC_SCENE_GAME) $(SRC_SCENE_INVENTORY) \
			$(SRC_SCENE_FIGHT)


%.o:	%.c
	gcc -o $@ -c $< $(FLAGS)

wc:
	wc  	$(SRC) $(SRC_BUTTONS)  \
		$(SRC_EVENTS) $(SRC_FREE)  \
		$(SRC_LIST) $(SRC_TEXTFIELD) \
		$(SRC_SCENES) $(SRC_SPRITES) \
		$(SRC_TEXTS) $(SRC_UTILS) \
		$(SRC_ITEMS) $(SRC_DATA) \
		$(SRC_INVENTORY) $(SRC_SCENE_MAIN_MENU) \
		$(SRC_PARSER) $(SRC_SCENE_GAME) \
		$(SRC_SCENE_FIGHT) $(SRC_SCENE_OPTION) \
		$(SRC_SCENE_PAUSE) $(SRC_SCENE_QUEST) \
		$(SRC_SCENE_INTRO) $(SRC_SCENE_CUTSCENE) \
		$(SRC_PLAYER) $(SRC_MAP)

$(NAME):	$(OBJ)
	make -C./lib/my/
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(CFLAGS) -lc_graph_prog

mac:	$(OBJ)
	make -C ./lib/my/
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(CFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

re:	fclean all

clean:
	rm -f $(OBJ) *~ \#*\# \

fclean:	clean
	make fclean -C./lib/my
	rm -f $(NAME)
