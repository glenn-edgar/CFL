# Makefile

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra

# Include directories
INCDIRS := . include
INCFLAGS := $(foreach dir,$(INCDIRS),-I$(dir))

# Source file directories
SRCDIR := .
SUBDIRS := named_queues engine heap storeage state_machines basic_chain_flow bit_register_operations

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.c)
SUB_SOURCES := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))
ALL_SOURCES := $(SOURCES) $(SUB_SOURCES)

# Object file directory
OBJDIR := obj

# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
SUB_OBJECTS := $(foreach dir,$(SUBDIRS),$(patsubst $(dir)/%.c,$(OBJDIR)/$(dir)/%.o,$(wildcard $(dir)/*.c)))
ALL_OBJECTS := $(OBJECTS) $(SUB_OBJECTS)

# Static library directory
LIBDIR := lib

# Static library
LIBRARY := $(LIBDIR)/libCFL.a

.PHONY: all clean

all: $(LIBRARY)

$(LIBRARY): $(ALL_OBJECTS)
	@mkdir -p $(@D)
	ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%/*.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -rf $(LIBRARY) $(OBJDIR)
