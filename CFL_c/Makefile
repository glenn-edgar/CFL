# Variables
CC = gcc
CFLAGS = -Wall
AR = ar
ARFLAGS = rcs
SRC_DIR = .
LIB_DIR =  lib
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(LIB_DIR)/%.o, $(SRC))
LIB = $(LIB_DIR)/libCFL.a

# Default target
all: $(LIB)

# Generate static library from object files
$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Compiling every C source file to corresponding object file
$(LIB_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up
clean:
	rm -f $(LIB_DIR)/*.o $(LIB)

