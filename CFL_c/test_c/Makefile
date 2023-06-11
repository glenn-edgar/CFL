# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11 -I../include -I./include
LIB_DIR = ../lib
LIBS = -lCFL
SRC = $(wildcard *.c) $(wildcard basics/*.c) $(wildcard unit_tests/*.c) \
               $(wildcard state_machine/*.c) $(wildcard named_and_column_events/*.c) \
			   $(wildcard data_flow/*.c)
OBJ_DIR = obj
OBJ_SUBDIRS = $(sort $(dir $(OBJ)))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
TARGET = CFL_test


# Default target
all: run_lua $(TARGET)

# Run ./lua before compilation
run_lua:
	./lua


# Linking the target executable
$(TARGET): $(OBJ)
	$(CXX) -L$(LIB_DIR) $^ -o $@ $(LIBS)

# Compiling every cpp file to corresponding object file
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning up
clean:
	rm -rf $(OBJ_DIR)/*  $(TARGET)

$(OBJ_SUBDIRS):
	@mkdir -p $@

$(OBJ): | $(OBJ_SUBDIRS)
