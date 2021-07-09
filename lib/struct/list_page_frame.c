#include "list_page_frame.h"

void init_page_frame_list(Plist *L, void (*destory)(void *data))
{
	(*L)->list_len = 0;
	(*L)->destory = destory;
	//(*L)->head = NULL;
	//(*L)->tail = NULL;
	list_head(*L) = NULL;
	list_tail(*L) = NULL;
}


/*
 * @breif Insert data after pnode(Insert data while pnode == NULL)
 * @param L a link list
 * @param pnode a typefo Pnode instance
 * @param *data insert the pointer of the data
 * @return 
 *	-<em>-1</em> fail
 *	-<em>0</em> success
 * */
int list_ins_next(Plist L, Pnode pnode, const void *data)
{

	Pnode pnode_new = (Pnode)malloc(sizeof(Node));
	if (!pnode_new) {
		printf("No enough memory space left!\n");
		return -1;
	}
	pnode_new->data = (void *)data;

	if (pnode == NULL) {
		/* Insert pnode_new at L head, not after head */
		if (L->list_len == 0) {
			list_tail(L) = pnode_new;
		}

		pnode_new->next = list_head(L);
		list_head(L) = pnode_new;
		//pnode_new->next = L->head;
		//L->head = pnode_new;
	} else {
		/* Insert pnode_new after pnode */
		if (pnode->next == NULL) {
			list_tail(L) = pnode_new;
		}

		list_next(pnode_new) = list_next(pnode);
		list_next(pnode) = pnode_new;
		//pnode_new->next = pnode->next;
		//pnode->next = pnode_new;
	}

	L->list_len++;

	return 0;
}

/*
 * @breif remove data after pnode(remove head while pnode == NULL)
 * @param L a link list
 * @param pnode a typefo Pnode instance
 * @param *data store the pointer of next delete Pnode
 * @return 
 *	-<em>-1</em> fail
 *	-<em>0</em> success
 * */
int list_rem_next(Plist L, Pnode pnode, const void **data)
{

	Pnode old_pnode;

	if (L->list_len == 0) {
		printf("The list is empty, no more to delete!\n");
		return -1;
	}

	if (pnode == NULL) {

		*data = (void *)list_head(L)->data;
		old_pnode = list_head(L);
		list_head(L) = list_next(list_head(L));

		if (list_length(L) == 1) {
			list_tail(L) = NULL;
		}
	} else {
		if (pnode->next == NULL) {
			printf("pnode is the last node, Can't delete the node after it!\n");
			return -1;
		}

		*data = (void *)list_data(list_next(pnode));
		old_pnode = list_next(pnode);
		list_next(pnode) =  list_next(list_next(pnode));
		if (list_next(pnode) == NULL) {
			list_tail(L) = NULL;
		}
	}

	free(old_pnode);
	L->list_len--;

	return 0;
}

void destory_page_frame_list(Plist *L)
{

	void **data;

	while (list_length(*L) > 0) {
		if (list_rem_next(*L, NULL, (void **)&data) == 0 && (*L)->destory != NULL) {
		(*L)->destory(data);
		}
	}

	//memset(*L, 0, sizeof(Plist));
}

int print_list(Plist L)
{

	if (list_length(L) == 0) {
		printf("The list is empty, stop printing!\n");
		return 0;
	}

	Pnode m = list_head(L)->next;

	printf("List Length:%d\n", L->list_len);
	while (m) {
		printf("data:0x%p->", (int *)m->data);
		m = m->next;
	}
	printf("NULL\n");
}
