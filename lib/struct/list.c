#include "list.h"

int destory_list(Plist *L)
{
	Plist *cur = L, tmp;
	if ((*L)->list_len == 0) {
		printf("Empty list, no more delete!\n");
		return -1;
	}

	while ((*cur)->next) {
		tmp = (*cur)->next;
		free((*cur));
		(*cur) = tmp;
	}
	free(*L);

}

int insert_list(Plist L, int i, Plist pnode)
{
	Plist m = L;
	while (i--) {
		m = m->next;
	}

	pnode->next = m->next;
	m->next = pnode;
	L->list_len++;
}

int init_list(Plist *L, int n)
{
	int i;
	Plist pnode;
	*L = (Plist)malloc(sizeof(List));
	if (!*L) {
		goto no_mem_head;
	}
	(*L)->list_len = 0;
	(*L)->next = NULL;
	for (i = 0; i < n; i ++) {
		pnode = (Plist)malloc(sizeof(List));
		if (!pnode) {
			goto no_mem_elem;
		}
		pnode->data = i;
		insert_list(*L, 0, pnode);
	}
	return 0;
no_mem_elem:
	destory_list(L);
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
	while (m->next) {
		printf("data:%d->", m->data);
		m = m->next;
	}
	printf("NULL\n");
}
