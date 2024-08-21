TARGET=main
SOURCE=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o, $(SOURCE))
CC=gcc

$(TARGET):$(OBJS)
$(CC) -o $(TARGET) $(OBJS)

RM=rm


clean:
$(RM) $(OBJS) $(TARGET)
