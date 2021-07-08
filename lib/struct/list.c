#include "list.h"

int destory_list(Plist *L)
{
	Plist *cur = L, tmp;
	if ((*L)->list_len == 0) {
		printf("Empty list, no more destory!\n");
		free(*L);
		return -1;
	}

	while ((*cur)->next) {
		tmp = (*cur)->next;
		free(*cur);
		(*cur) = tmp;
	}
	free(*L);

}

/* Insert the number to the i'th position in the list */
int insert_list(Plist L, int i, Plist pnode)
{
	Plist m = L;
	if (i <= 0 || (i > (L->list_len + 1))) {
		printf("Invalidate the number to insert to the list\n");
		return -1;
	}

	while (--i) {
		m = m->next;
	}

	pnode->next = m->next;
	m->next = pnode;
	L->list_len++;

	return 0;
}

int add_tail(Plist L, Plist pnode)
{
	Plist m = L, prev;
	while (m) {
		prev = m;
		m = m->next;
	}

	pnode->next = NULL;
	prev->next = pnode;
	L->list_len++;

	return 0;
}

int rem_list(Plist L, int n)
{
	Plist m = L, prev;

	if (!m->next) {
		printf("Can't delte an node from empty list!\n");
		exit(-1);
	}

	if (L->list_len < n || n <= 0) {
		printf("Can't delte %dth node from %d length list!\n", n, L->list_len);
		printf("Or the index number of list must selected from 0<n<=list_len\n");
		exit(-1);
	}

	while (n--&&m->next) {
		prev = m;
		m = m->next;
	}

	prev->next = m->next;
	free(m);
	if (L->list_len != 0)
		L->list_len--;
}

/* Init list by add to tail */
int init_list_tail(Plist *L, int n)
{

	Plist pnode;
	*L = (Plist)malloc(sizeof(List));
	if (!*L) {
		goto no_mem_tail;
	}

	(*L)->list_len = 0;
	(*L)->next = NULL;

	Plist r = *L;
	for (int i = 0; i < n; i++) {
		pnode = (Plist)malloc(sizeof(List));
		if (!pnode)
			goto no_mem_left;
		pnode->data = i;
#if 0
		add_tail(*L, pnode);
#elif 1
		pnode->next = NULL;
		r->next = pnode;
		r = pnode;
		(*L)->list_len++;
#endif
	}

	return 0;

no_mem_left:
	destory_list(L);
no_mem_tail:
	printf("No memory space for tail note!\n");
	return -1;
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
		insert_list(*L, 1, pnode);
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
	Plist m = L->next;
	if (!m) {
		printf("empty list!\n");
		return -1;
	}
	printf("List Length:%d\n", L->list_len);
	while (m) {
		printf("data:%d->", m->data);
		m = m->next;
	}
	printf("NULL\n");
}
