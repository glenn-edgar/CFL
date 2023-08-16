CC = gcc -I../../include
CFLAGS = -Wall -Wextra -Werror -g 
SRCS = $(wildcard *.c)
OBJS = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))
EXEC = test_CFL
LIBS = ../../lib/CFL.a

all: obj $(EXEC)

obj:
	mkdir -p obj

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS) 
	
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -rf obj $(EXEC)

.PHONY: all clean
