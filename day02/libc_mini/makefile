CC  = gcc
CFLAGS = -Wall -g -O0 # -g生成gdb调试符号，O0关闭优化
src = mini_string.c test_main.c
obj = $(src:.c=.o)
target = test_libc

all: &(target)

$(target): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $@

%o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(obj) $(target)