Q3 := $(if $(filter 3,$(V) $(VERBOSE)),,@)
Q2 := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
Q1 := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)

all: test
.PHONY: all

SUB_RULES := test clean fclean build

.PHONY: $(SUB_RULES)
$(SUB_RULES):
	$(Q2)make -C static_put $@
	$(Q2)make -C static_get $@
	$(Q2)make -C static_iterate $@
	$(Q2)make -C static_pop $@

.PHONY: re
re:
	$(Q3)$(MAKE) fclean
	$(Q3)$(MAKE) all
