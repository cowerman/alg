/*************************************************************************
    > File Name: ../lib/struct/array.c
    > Author:
    > Mail:
    > Created Time: 2019年07月08日 星期一 13时22分19秒
 ************************************************************************/

#include <stdio.h>
#include "lib.h"
#include "array.h"

int array_insert(int *data, int idx, int len, int *array)
{
	int ret = 0,local_idx, i = 1;

	local_idx = idx;

	if (len < idx) {
		ret = -1;
		printf("Error: idx should not be larger then arrary length!\n");
		return ret;
	}

	while (i <= len - idx) {
		array[len - i] = array[len - i - 1];
		i ++;
	}

	array[local_idx - 1] = *data;

	return ret;
}

int array_del_idx(int idx, int len, int *array)
{
	int ret = 0, i = 0;

	if (len < idx) {
		ret = -1;
		printf("Error: idx should not be larger than idx!\n");
		return ret;
	}

	while (i <= len - idx) {
		array[idx - 1 + i] = array[idx + i];
		i ++;
	}

	array[len - 1] = 0;
	return ret;
}

int array_find(int *data, int len, int *array)
{
	int i, ret = -1;

	for (i = 0; i < len; i ++) {
		if (array[i] == *data) {
			return i;
		}
	}

	return ret;
}

int array_del_ctx(int *data, int len, int *array)
{
	int ret = 0, idx = 0;
	int i = 0;

	idx = array_find(data, len, array);

	if (idx != -1) {
		while (i <= len - idx) {
			array[idx + i] = array[idx + i + 1];
			i ++;
		}
	
		array[len - 1] = 0;
	} else {
		ret = -1;
	}

	return ret;
}
