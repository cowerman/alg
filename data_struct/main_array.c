/*************************************************************************
    > File Name: main_array.c
    > Author:
    > Mail:
    > Created Time: 2019年07月08日 星期一 12时35分15秒
    > Modified: v1 2021/5/3 
		Descriptor: invoking bubble sort after get the
		random array
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "array.h"
#include "alg.h"

#define ARRAY_LEN 20

int main(void)
{
	int ar[ARRAY_LEN] = {};
	int ret;
	int data_insert = 1000;
	int idx = 3;

	/* generate a random array */
	ret = gen_random_arry(ar, ARRAY_LEN);
	print_int_arry(ar, ARRAY_LEN);

	/* bubble sorting */
	bubble_sort(ar, ARRAY_LEN);
	print_int_arry(ar, ARRAY_LEN);

	/* insert a data_insert at idx position */
	ret = array_insert(&data_insert, idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	print_int_arry(ar, ARRAY_LEN);

	/* del from idx position */
	ret = array_del_idx(idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: delete error!\n");
		goto err0;
	}
	print_int_arry(ar, ARRAY_LEN);

	/* insert a data_insert at idx position */
	ret = array_insert(&data_insert, idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	print_int_arry(ar, ARRAY_LEN);

	/* delete data_insert */
	ret = array_del_ctx(&data_insert, ARRAY_LEN, ar);
	if (ret) {
		printf("Cant find the data!\n");
	}
	print_int_arry(ar, ARRAY_LEN);

	/* re-bubble sorting after insert and delete */
	bubble_sort(ar, ARRAY_LEN);
	print_int_arry(ar, ARRAY_LEN);

#if 1
	/* small case to calculate the count while first fount the number of 66 in random number */
	int int_66 = 66, flag_66 = 1, i = 1;
	/* find 66 */
	while (flag_66) {
		flag_66 = array_find(&int_66, ARRAY_LEN, ar);
		if (flag_66 == -1) {
			i ++;
			gen_random_arry(ar, ARRAY_LEN);
		} else {
			printf(" Total generate %d,First found the %d in random number:\n", i,int_66);
			print_int_arry(ar, ARRAY_LEN);
			flag_66 = 0;
		}
	}
#endif

	return ret;

err0:
	exit(-1);
}
