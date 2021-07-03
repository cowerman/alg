DIR := $(shell pwd)
OUT := $(DIR)/out

TARGET := excute

CFLAGS += -Werror -fstack-protector -g
LDFLAGS += 

CC := gcc

C_INCLUDE_PATH = -Iinclude/
C_INCLUDE_PATH += -Iinclude/lib/
C_INCLUDE_PATH += -Iinclude/lib/sort
C_INCLUDE_PATH += -Iinclude/lib/struct

SRCS_LIB += lib/lib.c
SRCS_SORT += lib/sort/sel.c
SRCS_SORT += lib/sort/insert.c
SRCS_SORT += lib/sort/bubble.c

SRCS_DATA_STRUCT += lib/struct/array.c
SRCS_DATA_STRUCT += lib/struct/list.c
#SRCS_DATA_STRUCT += lib/struct/bitmap.c
#SRCS_DATA_STRUCT += lib/struct/ring_buf.c
#SRCS_DATA_STRUCT += lib/struct/queue.c
#SRCS_DATA_STRUCT += lib/struct/heap.c
#SRCS_DATA_STRUCT += lib/struct/stack.c
#SRCS_DATA_STRUCT += lib/struct/hash_table.c
#SRCS_DATA_STRUCT += lib/struct/b_tree.c

#SRCS_C += sorting/select/main.c
#SRCS_C += sorting/insert/main.c
#SRCS_C += sorting/bubble/main.c

#SRCS_C += data_struct/linear_table/main_array.c
SRCS_C += data_struct/list/list_main.c

SRCS = $(SRCS_LIB) $(SRCS_C) $(SRCS_SORT) $(SRCS_DATA_STRUCT)
OBJS = $(patsubst %.c, $(OUT)/%.o, $(SRCS))

.PHONY:
all: clean $(OUT)/$(TARGET)

.PHONY:
$(OUT)/$(TARGET): $(OBJS)
	gcc $(LDFLAGS) $(OBJS) -o $@

.PHONY:
$(OUT)/%.o: %.c
	[ ! -e $@ ] && mkdir -p $(dir $@); \
	$(CC) $(C_INCLUDE_PATH) -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf $(OUT)
