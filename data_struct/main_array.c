/*************************************************************************
    > File Name: main_array.c
    > Author:
    > Mail:
    > Created Time: 2019年07月08日 星期一 12时35分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "array.h"

#define ARRAY_LEN 20

int main(void)
{
	int ar[ARRAY_LEN] = {};
	int ret;
	int data_insert = 1000;
	int idx = 3, len = 5;

	/* generate a random array */
	ret = gen_random_arr(ar, len);
	print_seq(ar, ARRAY_LEN);

	/* insert a 1000 at 18 */
	ret = array_insert(&data_insert, idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	print_seq(ar, ARRAY_LEN);

	/* del from idx */
	ret = array_del_idx(idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: delete error!\n");
		goto err0;
	}
	print_seq(ar, ARRAY_LEN);

	/* insert a 1000 at 18 */
	ret = array_insert(&data_insert, idx, ARRAY_LEN, ar);
	if (ret) {
		printf("Error: insert error!\n");
		goto err0;
	}
	print_seq(ar, ARRAY_LEN);

	/* delete data */
	ret = array_del_ctx(&data_insert, ARRAY_LEN, ar);
	if (ret) {
		printf("Cant find the data!\n");
	}
	print_seq(ar, ARRAY_LEN);

#if 1
	int int_66 = 66, flag_66 = 1, i = 0;
	/* find 66 */
	while (flag_66) {
		flag_66 = array_find(&int_66, ARRAY_LEN, ar);
		if (flag_66 == -1) {
			i ++;
			gen_random_arr(ar, ARRAY_LEN);
		} else {
			print_seq(ar, ARRAY_LEN);
			printf(" Total generate %d,Found the %d: \n", i,int_66);
			flag_66 = 0;
		}
	}
#endif

	return 0;

err0:
	exit(-1);
}
