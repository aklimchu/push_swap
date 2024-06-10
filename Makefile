# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 11:18:05 by aklimchu          #+#    #+#              #
#    Updated: 2024/06/10 15:13:18 by aklimchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable
NAME		= libftpush_swap.a
LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT_DIR)
AR			= ar rcs
RM			= rm -f

# Source / OBJ files / Includes
SRC 		= push_swap.c ft_atoi_long.c \
				swap_algo.c swap_utils.c \
				swap_utils_2.c lst_utils.c \
				swap_small.c
OBJ 		= $(SRC:.c=.o)
INCLUDE		= push_swap.h 

# Rules
all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $^ -c -o $@ -I $(INCLUDE)

$(NAME):	$(OBJ)
	@make bonus -C $(LIBFT_DIR)		# make libft
	@cp $(LIBFT_LIB) $(NAME)	# copy libft to current
	$(AR) $(NAME) $(OBJ)		# add ft_printf.o to libftpush_swap.a

clean:
	$(RM) $(OBJ) 
	@make clean -C $(LIBFT_DIR)

fclean:		clean 
	$(RM) $(NAME) $(LIBFT_LIB) $(LIBFT_DIR)/.bonus

re: 		fclean all

.PHONY: 	all test clean fclean re
