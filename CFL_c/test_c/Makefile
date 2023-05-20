# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11 -I../
LIB_DIR = ../lib
LIBS = -lCFL
SRC = $(wildcard *.c)
OBJ_DIR = obj
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
	rm -f $(OBJ_DIR)/*.o $(TARGET)
