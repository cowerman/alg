/*************************************************************************
    > File Name: ../include/lib/struct/array.h
    > Author:
    > Mail:
    > Created Time: 2019年07月08日 星期一 13时38分09秒
 ************************************************************************/

int array_insert(int *data, int idx, int len, int *array);
int array_del_idx(int idx, int len, int *array);
int array_del_ctx(int *data, int idx, int *array);
int array_find(int *data, int len, int *array);
