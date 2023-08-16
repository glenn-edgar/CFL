# Compiler settings
CC = gcc
CXX = g++
INCLUDES = -I../../../include
CFLAGS = -Wall -Wextra -Werror -g 
CXXFLAGS = $(CFLAGS)

# Source and Object files
C_SRCS = $(wildcard *.c)
CPP_SRCS = $(wildcard *.cpp)
OBJS = $(addprefix obj/,$(notdir $(C_SRCS:.c=.o) $(CPP_SRCS:.cpp=.o)))

# Output executable and libraries
EXEC = test_CFL
LIBS = ../../../lib/CFL.a

all: obj $(EXEC)

obj:
	mkdir -p obj

obj/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	rm -rf obj $(EXEC)

.PHONY: all clean
