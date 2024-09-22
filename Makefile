CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
AR = ar
ARFLAGS = rcs
RM = rm -f

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h $(LIBFT_HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re