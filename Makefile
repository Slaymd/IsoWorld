##
## EPITECH PROJECT, 2018
## my_world_2017
## File description:
## MF
##

SRC_TEST	=	src/map_point.c			\
			src/map_gen.c				\
			src/init_settings.c			\
			src/map_iso.c				\
			src/file_tools.c			\
			test/test_ext.c			\
			test/test_gen.c			\
			test/test_nbr_to_str.c		\
			test/test_float_to_str.c		\
			test/test_str_to_float.c		\
			src/float.c

SRC	=	src/main.c				\
		src/free.c				\
		src/save.c				\
		src/map_iso.c				\
		src/map_gen.c				\
		src/load_map.c				\
		src/map_disp.c				\
		src/map_point.c			\
		src/float.c				\
		src/map_vertex.c			\
		src/map_select.c			\
		src/file_tools.c			\
		src/ui/init_ui.c			\
		src/ui/funcs_ui.c			\
		src/events/event.c			\
		src/init_settings.c			\
		src/map_disp_angle.c		\
		src/ui/wintools_ui.c		\
		src/events/move_event.c		\
		src/ui/init_editor_ui.c		\
		src/events/scroll_event.c	\
		src/events/select_event.c

INTLIBS = -L./lib/ui -lui -L./lib/my -lmy -g3 -I./include/

MCFLAGS = -lcsfml-graphics -lcsfml-system -W -Wall -Wextra -lm

CFLAGS = -lc_graph_prog -W -Wall -Wextra -lm

all: make_lib
	gcc $(SRC) $(CFLAGS) $(INTLIBS) -o my_world

make_lib:
	make -C./lib/my
	make -C./lib/ui

my: make_lib
	gcc $(SRC) $(MCFLAGS) $(INTLIBS) -o my_world

test: make_lib
	gcc $(SRC_TEST) $(MCFLAGS) $(INTLIBS) -lcriterion -o tests

clean:
	rm -f *~
	rm -f #*#
	rm -f *.o

fclean:	clean
	rm -f my_world

fclean_test: fclean
	rm -f tests

re:	fclean all
