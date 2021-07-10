#ifndef LIST_PAGE_FRAME_H
#define LIST_PAGE_FRAME_H

#include "lib.h"

typedef struct node {
	void *data;
	struct node *next;
}Node, *Pnode;

typedef struct slist {
	int list_len;
	int (*match)(const void *key1, const void *key2);
	void (*destory)(void *data);
	Pnode head;
	Pnode tail;
}List, *Plist;

#define list_length(list) ((list)->list_len)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, ele) ((list)->head == (ele) ? 1 : 0)
#define list_is_tail(ele) ((ele)->next == NULL ? 1 : 0)
#define list_data(ele) ((ele)->data)
#define list_next(ele) ((ele)->next)

void init_page_frame_list(Plist *L, void (*destory)(void *data));
void destory_page_frame_list(Plist *L);
int list_ins_next(Plist L, Pnode pnode, const void *data);
int list_rem_next(Plist L, Pnode pnode, void **data);
int print_list(Plist L);

#endif
