# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omillan <omillan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 17:18:03 by omillan           #+#    #+#              #
#    Updated: 2021/03/30 15:34:34 by omillan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
FILES		=	cub3d.c\
				color.c\
				make_figures.c\
				key_hook.c\
				check_map.c\
				errors.c\
				make_struct.c\
				parser.c\
				utils.c\
				cast_ray.c\
				parser_utils.c\
				textures.c\
				map_check.c\
				map_work.c\
				sprite.c\
				sprite_utils.c\
				parser_utils_sec.c\
				free.c\
				bmp_file.c\
				bmp_file_utils.c

SRCS		=	$(addprefix srcs/, $(FILES))
OBJS		=	${SRCS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
INCLUDES	=	-I$(MLX_DIR) -I$(LIBFT_DIR) -Iincludes/
LXFLAGS		=	-framework OpenGL -framework AppKit
MLX			=	libmlx.a
MLX_DIR		=	minilib/
MLX_LIB		=	-lmlx -lm
LIBFT		=	libft.a
LIBFT_DIR	=	libft/
LIBFT_LIB	=	-lft
RM			=	rm -rf

all:		$(NAME)
			@echo "\033[33m""####################DONE!#########################"
$(NAME):	$(MLX) $(OBJS) $(LIBFT_DIR)$(LIBFT)
			@echo "\033[32m""=====CUB3D====="
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. $(MLX_LIB) $(LXFLAGS) -L\
			$(LIBFT_DIR) $(LIBFT_LIB)

%.o : %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
			@echo "\033[33m""####################START#########################"
			@echo "\033[35m""=====MLX====="
			@$(MAKE) -C $(MLX_DIR) 2> /dev/null
			@mv $(MLX_DIR)$(MLX) .

$(LIBFT_DIR)$(LIBFT):
			@echo "\033[34m""=====LIBFT====="
			@$(MAKE) -C $(LIBFT_DIR)

clean:
			@echo "\033[31m""=====MAKE CLEAN====="
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(MLX_DIR) clean
			$(RM) $(MLX)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
