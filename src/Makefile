Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh build/script/nproc.sh))

CC := clang
CCLD := clang
AR := ar
ARFLAGS := cr$(if $(filter 1,$(V) $(VERBOSE)),v,)
CPPFLAGS := $(shell find . -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

OBJ_DIR := .cache

SRCS_LIBFT_BST := $(shell find . -name "ft_bst_*.c" | grep -v /test/ | xargs)

default: all
.PHONY: default

PROFILE ?= release
ifeq ($(PROFILE),release)
CFLAGS += -O3 -DNDEBUG
else ifeq ($(PROFILE),debug)
CFLAGS += -g3 -DDEBUG
else
$(error Bad profile)
endif

TARGET ?= production
ifeq ($(TARGET),production)
CFLAGS += -DNDEVELOPMENT
else ifeq ($(TARGET),development)
CFLAGS += -DDEVELOPMENT
else
$(error Bad target)
endif

SUFFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER))
CFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)
LDFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

$(OBJ_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) $(ARFLAGS) $@ $^
$(OBJ_DIR)/%.exe:
	$Qmkdir -p $(@D)
	$Q$(CCLD) $(LDFLAGS) -o $@ $^
$(OBJ_DIR)/%$(SUFFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -MJ $@.part.json -MMD -o $@ -c $<

$(OBJ_DIR)/libft_bst$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT_BST))

.PHONY: all
all: $(OBJ_DIR)/libft_bst$(SUFFIX).a

.PHONY: clean
clean:
	$Qrm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean

.PHONY: re
re:
	$Q$(MAKE) NO_ADDITIONAL_J=1 fclean
	$Q$(MAKE) NO_ADDITIONAL_J=1 all

.PHONY: test
test:
	$Qfind . -type d -mindepth 1 -name "test" | xargs -L1 -I {} make -C {} test

.PHONY: compile_commands.json
compile_commands.json:
	$Q$(MAKE) -k PROFILE=debug TARGET=development all ; (printf "[" && find .cache -name "*.development.debug.o.part.json" | xargs cat && printf "]") > $@

.PHONY: dev
dev: compile_commands.json
	$Qfind . -type d -name test | xargs -L1 -I {} make -C {} dev

# dependencies
-include $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).d,$(SRCS))

%.o: .cache/mlx
