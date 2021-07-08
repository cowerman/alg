#ifndef LIST_H
#define LIST_H
#include "lib.h"

typedef struct slist {
	int data;
	int list_len;
	struct slist *next;
} List, *Plist;


int destory_list(Plist *L);
int insert_list(Plist L, int i, Plist pnode);
int add_tail(Plist L, Plist pnode);
int init_list(Plist *L, int n);
int print_slist(Plist L);
int rem_list(Plist L, int i);
int init_list_tail(Plist *L, int n);
#endif
