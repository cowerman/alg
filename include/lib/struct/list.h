#ifndef LIST_H
#define LIST_H

typedef struct slist {
	int data;
	int list_len;
	struct slist *next;
} List, *Plist;


int destory_list(Plist L, int n);
int insert_list(Plist L, int i, List node);
int init_list(Plist L, int n);
int print_slist(Plist L);
#endif
