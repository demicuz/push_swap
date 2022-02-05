NAME		:= push_swap

SRC_DIR		:= src
OBJ_DIR		:= obj
LIB_DIR		:= lib

LIBFT_DIR	:= libft

LIBFT		:= $(LIB_DIR)/libft.a

SRC_FILES	:= main.c \
               doubly_linked_list.c \
               init.c \
               array.c \
               utils.c \
               sort.c \
               stack.c \
               operations.c \
               get_next_line.c \
               get_next_line_utils.c

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			:= cc
CPPFLAGS	:= -I include -I $(LIBFT_DIR) -MMD -MP
CFLAGS		:= -Wall -Werror -Wextra -O1
LDFLAGS		:= -L $(LIB_DIR)
LDLIBS		:= -lft

.PHONY:	all bonus clean fclean re

all: $(NAME)

bonus:
	$(MAKE) --file=Makefile_checker

$(LIBFT): $(LIB_DIR)
	$(MAKE) --directory=$(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIB_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean --directory=$(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf checker
	$(MAKE) fclean --directory=$(LIBFT_DIR)

re: fclean all

-include $(OBJ:.o=.d)
