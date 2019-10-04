# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpusel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 12:53:27 by adpusel           #+#    #+#              #
#    Updated: 2019/09/26 12:53:34 by adpusel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTDIR = libft/

INCSDIR = includes/

SRCSDIR = src/

OBJSDIR = objs/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_ms.cd.0.c \
       ft_ms.cd.1.c \
       ft_ms.env.c \
       ft_ms.env.getters.c \
       ft_ms.env.set_unset.c \
       ft_ms.env.utils.c \
       ft_ms.execve.c \
       ft_ms.get_line.c \
       ft_ms.handle_dollar_and_tilde.0.c \
       ft_ms.handle_dollar_and_tilde.1.c \
       ft_ms.signal.c \
       ft_ms.start.c \
       ft_ms.utils.c \
       ft_ms.main.c

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -I $(INCSDIR) -I $(LIBFTDIR)$(INCSDIR) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

clean:
	rm -rf $(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re