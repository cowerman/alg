/*************************************************************************
    > File Name: lib.h
    > Author:
    > Mail:
    > Created Time: 2019年06月21日 星期五 15时38分13秒
 ************************************************************************/

enum list_type {
	ARRAY_LIST,
	LINK_LIST,
};

int swap(int *seq, int *next_seq);
int gen_random_arr(int *seq, int len);
void print_seq(int *seq, int len);
