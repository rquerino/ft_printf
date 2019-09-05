# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 11:43:07 by rquerino          #+#    #+#              #
#    Updated: 2019/09/05 11:56:32 by rquerino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libftprintf.a
# CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

OBJDIR := build
SRCDIR := src
HEADIR := includes

UNAME := $(shell uname -s)

SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(SRCS:%=$(OBJDIR)/%.d)

HEAD := $(shell find $(SRCDIR) -name "*.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))

LIBS := libft/libft.a
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME)

_$(NAME): $(LIBS)
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS)
ifeq ($(UNAME),Darwin)
	libtool -static -o $@ $(OBJS) $(LIBS)
else
	ar crT $(@) $(OBJS) $(LIBS)
endif
	ranlib $@

$(OBJDIR) $(HEADIR):
	@mkdir -p $@

-include $(DEPS)

$(OBJDIR)/%.c.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(LIBINCS)

$(HEADIR)/%.h:
	@mkdir -p $(dir $@)
	cp $(subst $(HEADIR),$(SRCDIR),$@) $@

$(LIBS):
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

clean:
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) clean)
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -rf $(OBJDIR)

fclean: clean
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) fclean)
	rm -f $(NAME)
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all

debug: fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) -g"
