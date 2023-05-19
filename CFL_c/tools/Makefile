# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

# Directories
SRC_DIR = .
LIB_DIR = lib

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(LIB_DIR)/%.o,$(SRC_FILES))

# Targets
LIB_TARGET = $(LIB_DIR)/CFL.so

# Rules
all: $(LIB_TARGET)

$(LIB_TARGET): $(OBJ_FILES)
	ar rcs $@ $^

$(LIB_DIR)/%.o: $(SRC_DIR)/%.c | $(LIB_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

clean:
	rm -rf $(LIB_DIR)

.PHONY: all clean

