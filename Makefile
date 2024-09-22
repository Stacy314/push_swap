# **************************************************************************** #
#                                   VARIABLES                                   #
# **************************************************************************** #

NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

# Directories
LIBFT_DIR   := libft
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := includes

# Libft
LIBFT       := $(LIBFT_DIR)/libft.a
LIBFT_HEADERS := $(LIBFT_DIR)/libft.h

# Source files
SRCS        := $(wildcard $(SRC_DIR)/*.c)
# Object files
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Headers
INCLUDES    := -I$(INC_DIR) -I$(LIBFT_DIR)

# **************************************************************************** #
#                                  RULES / TARGETS                              #
# **************************************************************************** #

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