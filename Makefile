# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 17:40:26 by arabenst          #+#    #+#              #
#    Updated: 2022/11/22 13:47:33 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCDIR		=	src
OBJDIR		=	obj
INCDIRS		=	$(SRCDIR) libft

CC			=	gcc
INCFLAGS	=	$(foreach D,$(INCDIRS),-I $(D))
CFLAGS		=	-Wall -Werror -Wextra $(INCFLAGS)

AR			=	ar
ARFLAGS		=	rcs

RM			=	rm
RMFLAGS		=	-f

LIBFT		=	libft/libft.a

SRCS		=	$(wildcard $(SRCDIR)/*.c)
OBJS		=	$(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
DEPS		=	$(foreach D,$(INCDIRS),$(wildcard $(D)/*.h))

$(NAME): $(OBJS) | $(LIBFT)
	cp $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	(cd libft && make && make clean)

$(OBJDIR):
	mkdir $(OBJDIR)

all: $(NAME)

bonus: all

clean:
	$(RM) $(RMFLAGS) $(wildcard $(OBJDIR)/*.o)
	if [ -d $(OBJDIR) ]; then rm -Rf $(OBJDIR); fi

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) test
	(cd libft && make fclean)

re: fclean all

test: all
	$(CC) -o test $(CFLAGS) $(NAME) test.c

.PHONY: all clean fclean re test