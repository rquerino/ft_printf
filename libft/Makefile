
NAME := libft.a
# CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := $(shell find $(SRCDIR) -type f -name "*.c" $(DISABLED))
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(SRCS:%=$(OBJDIR)/%.d)

HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))

LIBS :=
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

# This might not be necessary
# _INC := $(shell find $(SRCDIR) -type d)
# INCS := $(addprefix -I,$(_INC))

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME)

_$(NAME): $(LIBS)
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS)
	ar rc $@ $(OBJS) $(LIBS)
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

ci:
	@$(MAKE) -C tests ci
