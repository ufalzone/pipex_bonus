# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 18:16:42 by ufalzone          #+#    #+#              #
#    Updated: 2025/02/09 00:37:19 by ufalzone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Couleurs
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
RESET = \033[0m

# Nom de l'exécutable
NAME = pipex

# Répertoires
SRC_DIR = src
LIBFT_DIR = libft
INCLUDE_DIR = includes
OBJ_DIR = obj

# Fichiers sources et objets
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)

# Flags de compilation
CC = cc
CFLAGS = -I$(INCLUDE_DIR) -g3 -MMD -MP

# Librairie libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règles
.PHONY: all clean fclean re libft_clean libft_fclean

# Compilation principale
all: $(OBJ_DIR) $(LIBFT) $(NAME)
	@echo "$(YELLOW)✨ Tout est à jour !$(RESET)"

# Compile la libft
$(LIBFT):
	@printf "$(BLUE)🔨 Compilation de la libft...$(RESET)\r"
	@$(MAKE) -C $(LIBFT_DIR)

# Création du dossier obj et ses sous-dossiers
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ_FILES))

# Compile le projet push_swap
$(NAME): $(OBJ_FILES)
	@printf "$(GREEN)🚀 Compilation de $(NAME)...$(RESET)                                                                \r"
	@$(CC) $(OBJ_FILES) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@printf "\n$(YELLOW)🚀 Compilation fini ! $(GREEN)$(NAME) $(YELLOW)est prêt !$(RESET)                            \n"

# Règle de compilation des fichiers objets
$(OBJ_DIR)/%.o: %.c
	@printf "$(CYAN)🔄 Compilation de $<...$(RESET)\r"
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean: libft_clean
	@echo "$(RED)🧹 Nettoyage des fichiers objets...$(RESET)"
	@rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean libft_fclean
	@echo "$(RED)🗑️  Suppression de $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Recompile tout
re: fclean all

# Nettoyage spécifique à la libft
libft_clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean

-include $(DEP_FILES)
