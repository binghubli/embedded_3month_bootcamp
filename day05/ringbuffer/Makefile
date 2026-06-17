CC = gcc
CFLAGS = -Wall -g -O0
INC = -I./include
SRC_DIR = ./src
OBJ_DIR = ./obj

# 所有c文件
SRCS = $(SRC_DIR)/ring_buf.c $(SRC_DIR)/uart_sim.c $(SRC_DIR)/proto_parse.c $(SRC_DIR)/main_test.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = rb_test

all: dir $(TARGET)

dir:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@

# ASAN内存检测
asan: dir $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(INC) -o $(TARGET)_asan

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TARGET)_asan