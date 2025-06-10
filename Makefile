################################################################################
#                                                                              #
#	                                Vars                                       #
#                                                                              #
################################################################################

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
DEFAULT_ARGS = "3 2 1 6 5 8"
ARGS ?= $(DEFAULT_ARGS)

SRCS        = $(SRC_DIR)/main.c $(SRC_DIR)/parse_arg.c $(SRC_DIR)/push_swap.c \
              $(SRC_DIR)/radix.c $(SRC_DIR)/utils0.c $(SRC_DIR)/utils1.c \
			  $(SRC_DIR)/o_push_pop.c $(SRC_DIR)/o_rotate.c $(SRC_DIR)/o_rrotate.c \
			  $(SRC_DIR)/o_swap.c

OBJS        = $(OBJ_DIR)/main.o $(OBJ_DIR)/parse_arg.o $(OBJ_DIR)/push_swap.o \
              $(OBJ_DIR)/radix.o $(OBJ_DIR)/utils0.o $(OBJ_DIR)/utils1.o \
			  $(OBJ_DIR)/o_push_pop.o $(OBJ_DIR)/o_rotate.o $(OBJ_DIR)/o_rrotate.o \
			  $(OBJ_DIR)/o_swap.o

SILENT = @

################################################################################
#                                                                              #
#	                                Rules                                      #
#                                                                              #
################################################################################

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null
	$(SILENT)$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)
	@echo "██████╗░██╗░░░██╗░██████╗██╗░░██╗░░░░░░░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
	@echo "██╔══██╗██║░░░██║██╔════╝██║░░██║░░░░░░██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║░░░██║╚█████╗░███████║█████╗╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
	@echo "██╔═══╝░██║░░░██║░╚═══██╗██╔══██║╚════╝░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
	@echo "██║░░░░░╚██████╔╝██████╔╝██║░░██║░░░░░░██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
	@echo "╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝░░░░░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"

clean:
	$(SILENT)$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	$(SILENT)$(RM) -r $(OBJ_DIR)

fclean: clean
	$(SILENT)$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	$(SILENT)$(RM) $(NAME)

re: fclean all

run: $(NAME)
	@clear
	@./$(NAME) $(ARGS)

valgrind: $(NAME)
	@clear
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-fds=yes \
		--track-origins=yes \
		./$(NAME) $(ARGS)

funcheck: $(NAME)
	@clear
	@funcheck -a ./$(NAME) $(ARGS)

norm:
	@norminette $(SRCS) $(INCLUDE) || true

.PHONY: all clean fclean re run valgrind funcheck norm
