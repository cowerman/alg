/*************************************************************************
    > File Name: bubble.c
    > Author:
    > Mail:
    > Created Time: Mon 24 Jun 2019 10:55:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include "alg.h"
#include "lib.h"

void bubble_sort(int* seq, int len)
{
	int i,j;

	for (i = 0; i < len - 1; i++) {
		for (j = len - 1; j > 0; j--) {
			if (seq[j] < seq[j - 1]) {
				swap(&seq[j], &seq[j - 1]);
			}
		}

		// debug
		//printf("The step %d sorting:\n", i);
		//print_seq(seq, len);
	}

	return ;
}
