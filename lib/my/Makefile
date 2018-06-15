##
## EPITECH PROJECT, 2017
## auto-libmy Makefile
## File description:
## By Ndr
##

#Répertoire du projet
SRC_DIR=	$(realpath .)

#Répertoire des libs
LIB_DIR=	$(realpath ..)

#Répertoire des includes
INC_DIR=	$(realpath ../../include)

#Fichiers sources
SRC=		$(wildcard *.c)

#Fichiers objets (relicats de compilation)
OBJ=		$(SRC:.c=.o)

#Flags de compilation
CFLAGS=		-W -Wall -Wextra -pedantic -I$(INC_DIR)

#Nom du projet
NAME=		libmy.a

#Règles
all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) $(LIB_DIR)/$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LIB_DIR)/$(NAME)

re:		fclean all
