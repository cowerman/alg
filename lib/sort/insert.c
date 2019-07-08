/*************************************************************************
    > File Name: insert.c
    > Author:
    > Mail:
    > Created Time: Sat 22 Jun 2019 09:54:38 PM CST
 ************************************************************************/
#include <stdio.h>
#include "alg.h"
#include "lib.h"

void insert_sort(int *seq, int len)
{
	int j;

	for (int i = 1; i < len; i++) {
		int cur_min = seq[i];
		for (j = i - 1; j >= 0 && seq[j] > cur_min; j--) {
			seq[j + 1] = seq[j];
		}

		seq[j + 1] = cur_min;

		// debug
		//printf("The step %d sorting:\n", i);
		//print_seq(seq, len);
	}

	return ;
}
