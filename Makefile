##
## EPITECH PROJECT, 2019
## MUL_my_RPG_2019
## File description:
## Makefile
##

SRC = $(shell find . -not -path "*extern/*" -name '*.c')
OUT = my_rpg_exec
CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -I./include -L./extern -llua53 -lpthread -g3 -Og -g -Wall -W

$(OUT): re

clean:
	rm -rf *.o

fclean:
	rm -rf my_rpg
	rm -rf $(OUT)

re: fclean
	gcc $(SRC) $(CFLAGS) -o $(OUT)
	echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./extern ./my_rpg_exec" > ./my_rpg
	chmod +x ./my_rpg
