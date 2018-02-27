CFLAGS= -g
OBJS=main.o
BIN=shared-example

all: $(OBJS)
	$(CC) $^ -o $(BIN)

clean:
	$(RM) $(OBJS) $(BIN)

.PHONY:all clean
