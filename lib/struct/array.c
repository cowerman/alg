#include <stdio.h>
#include "lib.h"
#include "array.h"

int array_insert(int *data, int idx, struct data *ar)
{
	int ret = 0, i = 0;

	if (ARRAY_LEN < idx || idx <= 0) {
		ret = -1;
		printf("Error: idx should not greater then %d and idx > 0!\n", ARRAY_LEN);
		return ret;
	}
	if (ar->len >= ARRAY_LEN) {
		printf("Error: The array is full!\n");
		ret = -1;
		return ret;
	}

	ar->len += 1;
	while (i <= (ar->len - idx - 1)) {
		ar->random_num[(ar->len - 1) - i] = ar->random_num[(ar->len - 1) - i - 1];
		i ++;
	}

	ar->random_num[idx - 1] = *data;
	return ret;
}

int array_del_idx(int idx, struct data *ar)
{
	int ret = 0, i = 0;

	if (ar->len == 0) {
		ret = -1;
		printf("Error: the arrary is empty, don't support delete!\n");
		return ret;
	}

	ar->len -= 1;
	while (i <= ar->len - idx) {
		ar->random_num[idx - 1 + i] = ar->random_num[idx + i];
		i ++;
	}

	return ret;
}

int array_find(int *data, struct data ar)
{
	int i, ret = -1;

	for (i = 0; i < ar.len; i ++) {
		if (ar.random_num[i] == *data) {
			return i;
		}
	}

	return ret;
}

int array_del_ctx(int *data, struct data *ar)
{
	int ret = 0, idx = 0;
	int i = 0;

	if (ar->len == 0) {
		ret = -1;
		printf("Error: the arrary is empty, don't support delete!\n");
		return ret;
	}
	idx = array_find(data, *ar);

	ar->len -= 1;
	if (idx != -1) {
		while (i <= ar->len - idx) {
			ar->random_num[idx + i] = ar->random_num[idx + i + 1];
			i ++;
		}
	
	} else {
		ret = -1;
	}

	return ret;
}
