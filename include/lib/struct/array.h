#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_LEN 20
struct data {
	int random_num[ARRAY_LEN];
	int len;
};

int array_insert(int *data, int idx, struct data *);
int array_del_idx(int idx, struct data *);
int array_del_ctx(int *data, struct data *);
int array_find(int *data, struct data);

#endif
