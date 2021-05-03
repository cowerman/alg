/*************************************************************************
    > File Name: sel.c
    > Author:
    > Mail:
    > Created Time: 2019年06月21日 星期五 14时02分42秒
 ************************************************************************/
#include <stdio.h>
#include "alg.h"
#include "lib.h"

void sel_sort(int *seq, int len)
{
	int min_index;

	for (int i = 0; i < len - 1; i ++) {
		min_index = i;
		for (int j = i + 1; j < len; j ++)
			if (seq[min_index] > seq[j]) {
				min_index = j;
			}

		if (min_index != i) {
			swap(&seq[i],&seq[min_index]);
		}

		// debug: after setep sort
		//printf("After step %d sort:\n", i);
		//print_int_arry(seq,len);
	}

	return;
}
