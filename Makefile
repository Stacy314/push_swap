NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

LIBFT_DIR   := libft
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := includes

LIBFT       := $(LIBFT_DIR)/libft.a
LIBFT_HEADERS := $(LIBFT_DIR)/libft.h

SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES    := -I$(INC_DIR) -I$(LIBFT_DIR)

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