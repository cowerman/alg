//TODO: insert data at idx position, should re-sorting
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "array.h"
#include "alg.h"

int main(void)
{
	struct data ar;
	int ret;
	int data_insert = 1000;
	int idx = 1;

	/* generate a random array */
	ret = gen_random_arry(ar.random_num, ARRAY_LEN - 1);
	ar.len = ARRAY_LEN - 1;
	printf("Get the origin array:\n");
	print_int_arry(ar.random_num, ar.len);

	/* bubble sorting */
	bubble_sort(ar.random_num, ar.len);
	printf("After the sorting array:\n");
	print_int_arry(ar.random_num, ar.len);

	/* insert a data_insert at idx position */
	ret = array_insert(&data_insert, idx, &ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	printf("Insert %d at position %d:\n", data_insert, idx);
	print_int_arry(ar.random_num, ar.len);

	/* del from idx position */
	ret = array_del_idx(idx, &ar);
	if (ret) {
		printf("Error: delete error!\n");
		goto err0;
	}
	printf("Delete %d at position %d:\n", ar.random_num[idx], idx);
	print_int_arry(ar.random_num, ar.len);

	/* insert a data_insert at idx position */
	ret = array_insert(&data_insert, idx, &ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	printf("Insert %d at position %d:\n", data_insert, idx);
	print_int_arry(ar.random_num, ar.len);

	/* delete data_insert */
	ret = array_del_ctx(&data_insert, &ar);
	if (ret) {
		printf("Can't find the data!\n");
	}
	printf("Delete %d from array:\n", data_insert);
	print_int_arry(ar.random_num, ar.len);

	/* re-bubble sorting after insert and delete */
	bubble_sort(ar.random_num, ar.len);
	printf("After insert and delete operation, re-bubble:\n");
	print_int_arry(ar.random_num, ar.len);

#if 1
	/* small case to calculate the count while first fount the number of 66 in random number */
	int int_66 = 66, flag_66 = 1, i = 1;
	/* find 66 */
	while (flag_66) {
		flag_66 = array_find(&int_66, ar);
		if (flag_66 == -1) {
			i ++;
			gen_random_arry(ar.random_num, ar.len);
		} else {
			printf(" Total generate %d,First found the %d in random number:\n", i,int_66);
			print_int_arry(ar.random_num, ar.len);
			flag_66 = 0;
		}
	}
#endif

	return ret;

err0:
	exit(-1);
}
