##
## EPITECH PROJECT, 2018
## my_world_2017
## File description:
## MF
##

SRC	=	src/main.c				\
		src/free.c				\
		src/save.c				\
		src/map_iso.c				\
		src/map_gen.c				\
		src/map_disp.c				\
		src/map_tools.c			\
		src/map_point.c			\
		src/ui/init_ui.c			\
		src/ui/funcs_ui.c			\
		src/events/event.c			\
		src/ui/wintools_ui.c			\
		src/events/key_press.c		\
		src/ui/init_editor_ui.c		\
		src/events/scroll_event.c	\
		src/events/select_event.c

INTLIBS = -L./lib/ui -lui -L./lib/my -lmy

MCFLAGS = -lcsfml-graphics -lcsfml-system -W -Wall -Wextra -lm -I./include/ -g3

CFLAGS = -lc_graph_prog -W -Wall -Wextra -lm -I./include/

all: make_lib
	gcc $(SRC) $(CFLAGS) $(INTLIBS) -o my_world

make_lib:
	make -C./lib/my
	make -C./lib/ui

my: make_lib
	gcc $(SRC) $(MCFLAGS) $(INTLIBS) -o my_world

clean:
	rm -f *~
	rm -f #*#
	rm -f *.o

fclean:	clean
	rm -f my_world

re:	fclean all
