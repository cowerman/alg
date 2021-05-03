/*************************************************************************
    > File Name: main.c
    > Author:
    > Mail:
    > Created Time: 2019年06月21日 星期五 15时33分25秒
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
	print_int_arry(ar, len);

	// sort the seq number
	bubble_sort(ar, len);

	// after sort the seq number
	print_int_arry(ar, len);
	return 0;
}
