# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 17:40:26 by arabenst          #+#    #+#              #
#    Updated: 2024/01/26 16:40:53 by arabenst         ###   ########.fr        #
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
RMFLAGS		=	-rf

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS		=	$(wildcard $(SRCDIR)/*.c)
OBJS		=	$(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
DEPS		=	$(foreach D,$(INCDIRS),$(wildcard $(D)/*.h))

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	git clone https://github.com/aaron-22766/libft.git $(LIBFT_DIR); make -C $(LIBFT_DIR)

all: $(NAME)

bonus: all

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) test
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re