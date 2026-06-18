CC = gcc
CFLAGS = -Wall -g -O0
INC = -I./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = fsm_demo

all: dir $(TARGET)

dir:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@

asan: dir $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(INC) -o $(TARGET)_asan

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TARGET)_asan