
SYS := $(shell clang -dumpmachine)

CC			=	clang

NAME		=	fractol

LNAME		=	ft

DIR			=	lib$(LNAME)

DIRMLX		=	minilibx

HDR			=	$(DIR)/$(DIR).a

SRC			= main.c					\
			ft_parser.c					\
			ft_init_glob_struct.c		\
			ft_julia_fract.c			\
			ft_put_pixel_to_image.c		\
			ft_mandel_fract.c			\
			ft_julia_mouse_events.c		\

OBJ			=	$(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS		=	-L$(DIR) -l$(LNAME)

WFLAGS 		=	-Wall -Wextra -Werror

CFLAGS1		=	$(WFLAGS) -I./includes/ -I./$(DIR) -I./$(DIRMLX)

OFLAGS		=	 -g

ifneq (, $(findstring linux, $(SYS)))
	MLXFLAG		= -L./$(DIRMLX) -I./$(DIRMLX) -lmlx -lXext -lX11 -lm
else
	MLXFLAG		= -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -lm
endif

HDR			=	$(DIR)/$(DIR).a

CFLAGS		=	$(CFLAGS1) $(OFLAGS)

all:		$(NAME) $(HDR)

$(NAME):	$(OBJ) $(HDR)
			make -C $(DIRMLX)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(MLXFLAG)

%.o: %.c
	$(CC) $(CFLAGS)  -c -o $@ $^

$(HDR):
		make -C $(DIR)

clean:
		make -C $(DIR) clean
		rm -f $(OBJ)

fclean:		clean
		make -C $(DIR) fclean
		make -C $(DIRMLX) clean
		rm -f $(NAME) $(HDR)

re:			fclean all

.PHONY: all clean fclean re
