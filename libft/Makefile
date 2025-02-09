# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 21:45:31 by ufalzone          #+#    #+#              #
#    Updated: 2025/02/09 01:08:31 by ufalzone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options
CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

# Répertoires
SRCDIR = srcs
PRINTF_DIR = ft_printf
INCDIR = includes
OBJDIR = obj

# Fichiers source
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
      ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
      ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
      ft_strdup.c ft_striteri.c ft_strjoin.c \
      ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
      ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
      ft_atol.c ft_isspace.c free_split.c ft_strjoin_three.c ft_strcmp.c\
      $(PRINTF_DIR)/core/ft_printf.c \
      $(PRINTF_DIR)/utils/ft_hex_utils.c \
      $(PRINTF_DIR)/utils/ft_numbers_utils.c \
      $(PRINTF_DIR)/utils/ft_redirect_utils.c \
      $(PRINTF_DIR)/utils/ft_strings_utils.c \
      ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
      ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
      ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
      get_next_line.c get_next_line_utils.c

# Objets
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Règles
.PHONY: all clean fclean re

# Compilation principale
all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)/$(PRINTF_DIR)/core
	@mkdir -p $(OBJDIR)/$(PRINTF_DIR)/utils

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJDIR)

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)

# Recompilation
re: fclean all
