CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L/usr/X11/lib -L./minilibx
LDLIBS = -lmlx -lXext -lX11 -lm
SRCSPATH = ./srcs
UTILSPATH = ./utils
GNLPATH = ./get_next_line
PRINTFPATH = ./ft_printf
MLXPATH = ./minilibx
LIBRPATH = ./utils

SRCS = $(SRCSPATH)/init_list.c $(SRCSPATH)/ft_atoil.c $(SRCSPATH)/init_window.c $(SRCSPATH)/draw_map.c $(SRCSPATH)/bresenham.c \
	   $(SRCSPATH)/create_coords.c
UTILS = $(UTILSPATH)/helpers.c $(UTILSPATH)/list_utils.c $(UTILSPATH)/draw_utils.c $(UTILSPATH)/atob.c
GNL = $(GNLPATH)/get_next_line.c $(GNLPATH)/get_next_line_utils.c

PRINTFA = $(PRINTFPATH)/libftprintf.a
MLXA = $(MLXPATH)/libmlx.a
LIBR = fdf.a
NAME = fdf

SRCOBJS = $(SRCS:.c=.o)
UTILSOBJS = $(UTILS:.c=.o)
GNLOBJS = $(GNL:.c=.o)
OBJS =$(GNLOBJS) $(UTILSOBJS) $(SRCOBJS)


%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.c $(LIBR)
		@$(CC) $(CFLAGS) $(LDFLAGS) main.c $(LIBR) -o $(NAME) $(LDLIBS)
		@echo "Build complete"

all: $(NAME)

$(PRINTFA):
			@make -s -C $(PRINTFPATH)

$(MLXA):
		@make -s -C $(MLXPATH)

$(LIBR): $(PRINTFA) $(MLXA) $(OBJS)
		@ar x $(PRINTFA)
		@ar x $(MLXA)
		@ar rcs $(LIBR) $(OBJS) *.o
		@rm -f *.o


clean:
		@rm -f $(OBJS)
		@echo "Clean complete"

fclean:
		@rm -f $(OBJS)
		@rm -f $(NAME)
		@rm -f $(LIBR)
		@make -s -C $(PRINTFPATH) fclean
		@make -s -C $(MLXPATH) clean
		@echo "Clean complete"

re: fclean $(NAME)

.PHONY: all fclean clean re
