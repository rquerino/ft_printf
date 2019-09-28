# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 11:43:07 by rquerino          #+#    #+#              #
#    Updated: 2019/09/28 16:21:28 by rquerino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

UNAME := $(shell uname -s)

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := ./libft/src/ft_atoi.c \
		./libft/src/ft_bzero.c \
		./libft/src/ft_final_spaces.c \
		./libft/src/ft_initial_spaces.c \
		./libft/src/ft_isalnum.c \
		./libft/src/ft_isalpha.c \
		./libft/src/ft_isascii.c \
		./libft/src/ft_isdigit.c \
		./libft/src/ft_isprint.c \
		./libft/src/ft_isspace.c \
		./libft/src/ft_itoa.c \
		./libft/src/ft_lstadd.c \
		./libft/src/ft_lstdel.c \
		./libft/src/ft_lstdelone.c \
		./libft/src/ft_lstiter.c \
		./libft/src/ft_lstmap.c \
		./libft/src/ft_lstnew.c \
		./libft/src/ft_memalloc.c \
		./libft/src/ft_memccpy.c \
		./libft/src/ft_memchr.c \
		./libft/src/ft_memcmp.c \
		./libft/src/ft_memcpy.c \
		./libft/src/ft_memdel.c \
		./libft/src/ft_memmove.c \
		./libft/src/ft_memset.c \
		./libft/src/ft_putchar.c \
		./libft/src/ft_putchar_fd.c \
		./libft/src/ft_putendl.c \
		./libft/src/ft_putendl_fd.c \
		./libft/src/ft_putnbr.c \
		./libft/src/ft_putnbr_fd.c \
		./libft/src/ft_putstr.c \
		./libft/src/ft_strlcat.c \
		./libft/src/ft_strlen.c \
		./libft/src/ft_putstr_fd.c \
		./libft/src/ft_strmap.c \
		./libft/src/ft_strcat.c \
		./libft/src/ft_strchr.c \
		./libft/src/ft_strclr.c \
		./libft/src/ft_strcmp.c \
		./libft/src/ft_strcpy.c \
		./libft/src/ft_strdel.c \
		./libft/src/ft_strdup.c \
		./libft/src/ft_strequ.c \
		./libft/src/ft_striter.c \
		./libft/src/ft_striteri.c \
		./libft/src/ft_strstr.c \
		./libft/src/ft_strjoin.c \
		./libft/src/ft_strtrim.c \
		./libft/src/ft_tolower.c \
		./libft/src/ft_toupper.c \
		./libft/src/ft_strsub.c \
		./libft/src/ft_strmapi.c \
		./libft/src/ft_strncat.c \
		./libft/src/ft_ull_len.c \
		./libft/src/ft_ultoa.c \
		./libft/src/ft_strncmp.c \
		./libft/src/ft_utoa.c \
		./libft/src/ft_strncpy.c \
		./libft/src/ft_word_count.c \
		./libft/src/ft_strnequ.c \
		./libft/src/ft_word_length.c \
		./libft/src/ft_strnew.c \
		./libft/src/get_next_line.c \
		./libft/src/ft_strnstr.c \
		./libft/src/ft_strrchr.c \
		./libft/src/ft_strsplit.c \
		./src/aux.c \
		./src/ft_printf.c \
		./src/ft_printf_d.c \
		./src/ft_printf_p.c \
		./src/ft_printf_u.c \
		./src/read.c \
		./src/aux2.c \
		./src/ft_printf.c \
		./src/ft_printf_f.c \
		./src/ft_printf_perc.c \
		./src/printer.c \
		./src/ft_printf_x.c \
		./src/ft_dtoa.c \
		./src/ft_printf_c.c \
		./src/ft_printf_o.c \
		./src/ft_printf_s.c

OBJS := $(SRCS:%=$(OBJDIR)/%.o)

LIBS :=
# LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

# This might not be necessary
# _INC := $(shell find $(SRCDIR) -type d)
# INCS := $(addprefix -I,$(_INC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
ifeq ($(UNAME),Darwin)
	libtool -static -o $@ $(OBJS) $(LIBS)
else
	ar crT $(@) $(OBJS) -I libft/src -I src
endif
	ranlib $@

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@  -I libft/src -I src

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all
