NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/main.c $(SRC_DIR)/parse_arg.c $(SRC_DIR)/push_swap.c \
              $(SRC_DIR)/radix.c $(SRC_DIR)/utils0.c $(SRC_DIR)/utils1.c \
			  $(SRC_DIR)/o_push_pop.c $(SRC_DIR)/o_rotate.c $(SRC_DIR)/o_rrotate.c \
			  $(SRC_DIR)/o_swap.c

OBJS        = $(OBJ_DIR)/main.o $(OBJ_DIR)/parse_arg.o $(OBJ_DIR)/push_swap.o \
              $(OBJ_DIR)/radix.o $(OBJ_DIR)/utils0.o $(OBJ_DIR)/utils1.o \
			  $(OBJ_DIR)/o_push_pop.o $(OBJ_DIR)/o_rotate.o $(OBJ_DIR)/o_rrotate.o \
			  $(OBJ_DIR)/o_swap.o

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./libft/libft.a

clean:
	$(MAKE) -C ./libft clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
