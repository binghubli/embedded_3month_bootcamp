# 基础配置
CC      = gcc
CFLAGS  = -Wall -g -O0
INC     = -I./include        # 头文件路径
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib

# 源文件
SRC     = $(SRC_DIR)/calc.c $(SRC_DIR)/log.c $(SRC_DIR)/main.c
OBJS    = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

# 库相关
LIB_SRC = $(SRC_DIR)/calc.c $(SRC_DIR)/log.c
LIB_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(LIB_SRC)))
STATIC_LIB = $(LIB_DIR)/libcalc.a
DYNAMIC_LIB = $(LIB_DIR)/libcalc.so
TARGET  = app

# 默认目标：编译可执行程序
all: dir $(TARGET)

# 创建目录
dir:
	mkdir -p $(OBJ_DIR) $(LIB_DIR)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@

# 编译 .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# ========== 编译静态库 .a ==========
static_lib: dir $(STATIC_LIB)
$(STATIC_LIB): $(LIB_OBJ)
	ar rcs $@ $(LIB_OBJ)
	@echo "静态库生成完成: $(STATIC_LIB)"

# ========== 编译动态库 .so ==========
dynamic_lib: dir $(DYNAMIC_LIB)
$(DYNAMIC_LIB): $(LIB_SRC)
	$(CC) $(CFLAGS) -fPIC -shared $(LIB_SRC) $(INC) -o $@
	@echo "动态库生成完成: $(DYNAMIC_LIB)"

# 清理所有产物
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(TARGET) *.i *.s *.o