CFLAGS += -Wall
LDFLAGS += -g

CC := gcc

INCLUDE_PATH += include/
INCLUDE_PATH += include/lib/

SRCS_LIB += lib/lib.c

SRCS_C += sorting/select/sel.c
SRCS_C += sorting/select/main.c

SRCS = $(SRCS_LIB) $(SRCS_C)
OBJS = $(SRCS:.c=.o)

-include $(OBJS:.o=.d)
-include $(OBJS:.o=.d)

export INCLUDE_PATH

.PHONY:
all: excute

.PHONY:
excute: $(OBJS)
	#$(CC)  $(patsubst %, -I%, $(INCLUDE_PATH)) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
	$(CC)  -Iinclude/lib -Iinclude/ $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
