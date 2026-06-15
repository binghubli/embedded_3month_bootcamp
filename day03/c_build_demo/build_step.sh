#!/bin/bash
# 演示 C 四大编译流程：预处理、编译、汇编、链接

SRC=src/main.c
INC=./include

rm -f *.i *.s *.o app 

echo "===== 1. 预处理 -E 生成 .i 文件 ====="
gcc -E $SRC -I$INC -o main.i

echo "===== 2. 编译 -S 生成汇编 .s 文件 ====="
gcc -S main.i -o main.s

echo "===== 3. 汇编 -c 生成目标文件 .o ====="
gcc -c main.s -o main.o

echo "===== 4. 链接 生成可执行文件 ====="
gcc main.o src/calc.c src/log.c -I$INC -o app

echo "编译完成，执行 ./app"