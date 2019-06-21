/*************************************************************************
    > File Name: lib.c
    > Author:		
    > Mail:		
    > Created Time: 2019年06月21日 星期五 15时32分18秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lib.h"

int swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

	return 0;
}

int gen_seq(int *seq, int len)
{
	srandom(time(NULL));

	for (int i = 0; i < len; i++) {
		seq[i] = random() % 100;
	}

	return 0;
}

void print_seq(int *seq, int len)
{
	for (int i = 0; i < len; i++) {
		printf(" %d",seq[i]);
	}
	printf("\n");

	return;
}

