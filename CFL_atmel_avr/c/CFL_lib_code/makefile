CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Os -s
INCLUDES = -I../include

SRCS = $(wildcard *.c)
OBJS = $(addprefix obj/,$(SRCS:.c=.o))
LIB = ../lib/CFL.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

obj:
	mkdir -p obj

clean:
	rm -rf obj $(LIB)
