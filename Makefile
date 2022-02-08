#NAME
NAME = so_long

#COMPILER
CC = clang

#COMPILER FLAGS
CFLAGS += -Wall
CFLAGS += -Wextra

#ERROR FLAGS
ifneq ($(err), no)
	CFLAGS += -Werror
endif

#DEBUG FLAGS
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address
else ifeq ($(debug), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Weverything
endif

#DEBUGS SYMBOLS
DSYM += $(NAME).dSYM 

#INCLUDES 
INCLUDES += includes

#LIB 
PATH_LIB = libftprintf
LIB = $(PATH_LIB)/libftprintf.a
INCLUDES_LIB = ./$(PATH_LIB)/includes
LIB_NAME = ftprintf

PATH_LIBMLX = ./mlx
LIBMLX = $(PATH_LIBMLX)/libmlx.a
INCLUDES_LIBMLX = $(PATH_LIBMLX)
LIBMLX_NAME = mlx

MLXLIB =  -lm -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit
#-lft

#PATH_SOURCES 
PATH_SRCS = srcs

#SOURCES
SRCS += so_long.c
SRCS += file_checker.c
SRCS += map_filler.c
SRCS += map_checker.c
SRCS += image_access_checker.c
SRCS += exit_routines.c
SRCS += print_map.c
SRCS += initialize_player_collectible.c
SRCS += hook.c
SRCS += end_game.c
SRCS += get_images.c
SRCS += display_map_components.c

#HEADERS
HEADERS += so_long.h

#VPATH
vpath %.c $(PATH_SRCS)
vpath %.h $(INCLUDES)

#OBJS
PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#COLORS PRINT
NC 		= \033[0m
GREEN 	= \033[32m
CYAN 	= \033[36m
RED 	= \033[31m
ONELINE = \e[1A\r


#RULES 

all: $(NAME)

$(NAME): $(LIB) $(LIBMLX) $(PATH_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -I $(INCLUDES_LIBMLX) -I $(INCLUDES_LIB) -L $(PATH_LIB) -l$(LIB_NAME) -L $(PATH_LIBMLX) -l$(LIBMLX_NAME) $(MLXLIB) -o $@
	printf "$(GREEN)$@ IS READY\n$(NC)"						#./mlx_linux/libmlx_Linux.a												/usr/lib/libXext.a					

$(LIB): FORCE
	#make -C libftprintf 
	$(MAKE) -C $(PATH_LIB) 
	$(MAKE) -C $(PATH_LIBMLX) 


FORCE: 
	#permet de forcer la réalisationn de la lib

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_LIB) -I $(INCLUDES_LIBMLX) -I $(INCLUDES) -c $< -o $@
	printf "$(CYAN)$< IS COMPILING                                 \n$(NC)"

$(PATH_OBJS):
	mkdir $@

clean:
	$(MAKE) -C $(PATH_LIB) clean 
	$(MAKE) -C $(PATH_LIBMLX) clean 
	$(RM) -R $(PATH_OBJS) $(DSYM)
	printf "$(RED)IT'S CLEAN\n$(NC)"

fclean: clean
	$(MAKE) -C $(PATH_LIB) fclean 
	$(MAKE) -C $(PATH_LIBMLX) clean 
	$(RM) $(NAME)
	printf "$(RED)$(NAME) REMOVED\n$(NC)"

re: fclean
	$(MAKE) -C $(PATH_LIB) re 
	$(MAKE) -C $(PATH_LIBMLX) re 
	$(MAKE)

.PHONY: clean fclean re all FORCE 

.SILENT: 
