# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 17:40:26 by arabenst          #+#    #+#              #
#    Updated: 2023/10/19 13:17:17 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

OBJDIR	=	./obj

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

AR		=	ar
ARFLAGS	=	rcs

RM		=	rm
RMFLAGS	=	-Rf

SRCS	=	$(wildcard */*.c) \
			$(wildcard */*/*.c) \
			$(wildcard */*/*/*.c)
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Libft compiled"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re