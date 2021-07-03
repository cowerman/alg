#include "list.h"
#include "lib.h"

int destory_list(Plist L, int k)
{
	Plist m, n;
	m = L;
	if (L->list_len == 0) {
		printf("Empty list, no more delete!\n");
		return -1;
	}
	for (int i = 0; i < k; i ++) {
		m = m->next;
	}
	n = m->next;
	free(n);
	m->next = NULL;
	L->list_len++;
}

int insert_list(Plist L, int i, List node)
{
	Plist m = L;
	while (i--) {
		m = m->next;
	}

	node.next = m->next;
	m->next = &node;
	L->list_len++;
}



int init_list(Plist L, int n)
{
	int i;
	Plist pnode;
	L = (Plist)malloc(sizeof(List));
	if (!L) {
		goto no_mem_head;
	}
	L->list_len = 0;
	L->next = NULL;

	for (i = 0; i < n; i ++) {
		pnode = (Plist)malloc(sizeof(List));
		if (!pnode) {
			goto no_mem_elem;
		}
		pnode->data = gen_random_num();
		insert_list(L, 0, *pnode);
	}

	return 0;
no_mem_elem:
	for (int j = i - 1; j >= 0; j --) {
		destory_list(L, j);
	}
	free(L);
no_mem_head:
	printf("No memory space for head note!\n");
	return -1;
}

int print_slist(Plist L)
{
	Plist m = L;
	if (!L) {
		printf("Empty list!\n");
		return -1;
	}
	printf("List Length:%d\n", L->list_len);
	while (!m->next) {
		printf("data:%d->", m->data);
		m = m->next;
	}
	printf("NULL\n");
}
