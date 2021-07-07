#include "list.h"

int main(int argc, char *argv[])
{
	int n = 5;
	Plist L;
	init_list(&L, n);
	print_slist(L);

	destory_list(&L);
	return 0;
}
