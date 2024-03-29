/*************************************************************************
    > File Name: main.c
    > Author:
    > Mail:
    > Created Time: Sat 22 Jun 2019 09:51:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include "alg.h"
#include "lib.h"

#define NUM 10

int main(void)
{
	int ar[NUM];
	int len = sizeof(ar) / sizeof(ar[0]);

	// generate seq number
	gen_random_arry(ar, len);

	// before sorting
	print_int_arry(ar, len);

	// insert sort
	insert_sort(ar, len);

	// after sorting
	print_int_arry(ar, len);
	return 0;
}
