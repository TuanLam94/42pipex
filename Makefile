# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:59:27 by tlam              #+#    #+#              #
#    Updated: 2024/01/23 14:59:28 by tlam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -rf

SRCS = src/main.c \
		src/utils.c \
		src/pipex.c \
		libft/libft.a \

SRCS_BONUS = src_bonus/main_bonus.c \
		src_bonus/utils_bonus.c \
		src_bonus/pipex_bonus.c \
		src_bonus/init_bonus.c \
		src_bonus/here_doc.c \
		src_bonus/get_next_line_bonus.c \
		src_bonus/get_next_line_utils_bonus.c \
		libft/libft.a \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = includes/pipex.h

HEADER_BONUS = includes/pipex_bonus.h

$(NAME) : $(OBJS) $(LIBFT)
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(HEADER) $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_PATH) all

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

all : $(LIBFT_PATH) $(NAME)

bonus : $(OBJS_BONUS) $(LIBFT)
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME) -I $(HEADER_BONUS) $(LIBFT)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re bonus
