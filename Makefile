##
## EPITECH PROJECT, 2018
## 102architect
## File description:
## compilation
##

SRC =       $(wildcard *.c)

OBJ =   $(SRC:.c=.o)

NAME =  102architect

RM = rm -f -r

$(NAME):    $(OBJ)
		gcc -g $(OBJ) -o $(NAME) -lm
		rm -f $(OBJ)

all:    $(NAME)

clean:
	@$(RM) *~
	@$(RM) *.o
	@printf "Les fichiers ~ et .o ont été supprimé\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Le fichier cat a été supprimé\n"

re: fclean all
