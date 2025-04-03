# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 14:21:58 by brturcio          #+#    #+#              #
#    Updated: 2025/03/22 13:36:14 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables principales
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
CPPFLAGS    = -Iinc -Ilibft -Ift_printf
RM          = rm -f

# Directorios
OBJ_DIR     = obj
SRC_DIR     = src
LIBFT_DIR   = ./libft
PRINTF_DIR  = ./ft_printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# Flags para enlazar librerías
LDFLAGS     = -L$(LIBFT_DIR) -L$(PRINTF_DIR)
LDLIBS      = -lft -lftprintf

# Archivos fuente y objetos
SRC         = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Regla principal
all: $(LIBFT) $(PRINTF) $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@echo "✅ Compilación completada: $(NAME)"

# Compilar libft
$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

# Compilar ft_printf
$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Generar los archivos .o en obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpiar archivos intermedios
clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@echo "🧹 Archivos intermedios eliminados."

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "🧹 Proyecto limpio."

# Reglas PHONY
.PHONY : all clean fclean re debug

# Reconstruir todo
re: fclean all

# -------------------- DEPURACIÓN --------------------
debug: CFLAGS += -g
debug: re
	@echo "Compilado con -g para depuración."


