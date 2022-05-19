CC=gcc
INCLUDE_PATH=../INCLUDE
LIBRARY_PATH=../LIBRARY
TARGET=thread_pool_server

CFLAGS=-I$(INCLUDE_PATH) -c -g -Wall
LDFLAGS=-lpthread

RM=rm -rf


SRCFILE=$(wildcard *.c)
DESFILE=$(patsubst %.c,%.o,$(SRCFILE))


$(TARGET):$(DESFILE)
	$(CC) $^ $(LDFLAGS) -o $@



%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	$(RM)  $(TARGET)
	$(RM)  $(DESFILE)
	





