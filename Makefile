# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 14:21:58 by brturcio          #+#    #+#              #
#    Updated: 2025/04/03 13:51:08 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
CPPFLAGS    = -Iinc -Ilibft -Ift_printf
RM          = rm -f

OBJ_DIR     = obj
SRC_DIR     = src
LIBFT_DIR   = ./libft
PRINTF_DIR  = ./ft_printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a

LDFLAGS     = -L$(LIBFT_DIR) -L$(PRINTF_DIR)
LDLIBS      = -lft -lftprintf

SRC         = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@echo "✅ Compilation completed: $(NAME) "

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@echo "✅ clean done. "

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "✅ fclean done. "

.PHONY : all clean fclean re debug

re: fclean all


