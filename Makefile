DIR := $(shell pwd)
OUT := $(DIR)/out

TARGET := excute

CFLAGS += -Wall -g
LDFLAGS += 

CC := gcc

C_INCLUDE_PATH = -Iinclude/
C_INCLUDE_PATH += -Iinclude/lib/

SRCS_LIB += lib/lib.c
SRCS_ALG += sorting/select/sel.c
SRCS_ALG += sorting/insert/insert.c
SRCS_ALG += sorting/bubble/bubble.c


#SRCS_C += sorting/select/main.c
#SRCS_C += sorting/insert/main.c
SRCS_C += sorting/bubble/main.c

SRCS = $(SRCS_LIB) $(SRCS_C) $(SRCS_ALG)
OBJS = $(patsubst %.c, $(OUT)/%.o, $(SRCS))

.PHONY:
all: $(OUT)/$(TARGET)

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
