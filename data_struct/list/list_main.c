#include "list.h"

int main(int argc, char *argv[])
{
	int n = 5;
	Plist L, m;
#if 0
	init_list(&L, n);
#elif 1
	init_list_tail(&L, n);
#endif
	printf("Init an 5 length list\n");
	print_slist(L);
	m = (Plist)malloc(sizeof(List));
	if (!m) {
		printf("No enough memory space!\n");
		exit(-1);
	}
#if 0
	printf("Add an interger data at list tail\n");
	m->data = 10;
	add_tail(L, m);
#elif 0
	printf("Add an interger data at list head\n");
	m->data = 10;
	insert_list(L, 5, m);
#elif 1
	printf("Remove an interger data by index from list\n");
	rem_list(L, 1);
#endif
	print_slist(L);
	destory_list(&L);
	free(m);
	return 0;
}
