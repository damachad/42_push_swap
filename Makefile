# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 10:57:36 by damachad          #+#    #+#              #
#    Updated: 2023/08/17 15:01:27 by damachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COLORS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COMMANDS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
CC = cc
RM = rm -rf

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FLAGS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
CFLAGS 	= -Wall -Werror -Wextra
MK_FLAG = --no-print-directory
LFLAGS 	= -L ./libft -lft

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PATHS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
INC			= includes
SRC_DIR		= srcs
OBJ_DIR		= objs

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FILES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
NAME 		= push_swap
LIBFT		= libft/libft.a
FILES 		= main validator operations operations2 sort clean \
			init stack cost
SRC 		= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ ARGUMENTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
NBRS_LIST = 0 2 4 6 7 8 9

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ RULES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) -I $(INC)
	@echo "[$(GREEN)$(NAME) created$(RESET)]"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "[$(GREEN)objs directory created$(RESET)]"

$(LIBFT):
	@make $(MK_FLAG) -C ./libft

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BNS_DIR)
	@make $(MK_FLAG) -C ./libft clean
	@echo "[$(RED)objs removed$(RESET)]"

fclean: clean
	@$(RM) $(NAME) $(NAME_BNS) $(LIBFT)
	@echo "[$(RED)executables and $(LIBFT) removed$(RESET)]"

re: fclean all

# valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes

test: $(NAME)
	@valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME) $(NBRS_LIST) 

# 3 numbers should be less than 3 operations
# 5 numbers should be less than 12 operations
# 100 numbers should be less than 700 operations to be perfect
# 500 numbers should be less than 5500 operations to be perfect

count: $(NAME)
	@./$(NAME) $(NBRS_LIST) | ./checker_linux $(NBRS_LIST)
	@./$(NAME) $(NBRS_LIST) | wc -l

output: $(NAME)
	@./$(NAME) $(NBRS_LIST) > output.txt

.PHONY: all clean fclean re test count output
