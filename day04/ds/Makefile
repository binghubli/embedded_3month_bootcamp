CC = gcc
CFLAGS = -Wall -g -O0 -I include
SRC = test_ds.c src/queue.c src/stack.c src/list.c
TARGET = test_ds

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

asan:
	$(CC) $(CFLAGS) -fsanitize=address $(SRC) -o $(TARGET)_asan

clean:
	rm -f $(TARGET) $(TARGET)_asan *.o