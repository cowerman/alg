/*
 * @breif List can used to be manage page frames
 *	pages frame is a free page frames list, it use a stack model to
 *	manage itself: 
 *	1. when a page frame freed from system, the page frame
 *	could be insert at the head of list.
 *	2. when a page frame is alloc by system, the page frame should
 *	be removed from the head of list.
 *
 * */

#include "list_page_frame.h"

int alloc_frame(Plist frame)
{

	int frame_number, *data;

	if (list_length(frame) == 0) {
		printf("free page frame is empty, can't alloc frame!\n");
		return -1;
	}

	/* alloc a frame number from free page frame list head */
	if (list_rem_next(frame, NULL, (void **)&data) != 0) {
		printf("cant retrieved from free page frame list!\n");
		return -1;
	} else {
		frame_number = *data;
		free(data);
	}

	return frame_number;
}

int free_frame(Plist frame, int frame_number)
{
	int *data;
	
	data = (int *)malloc(sizeof(int));
	if (!data) {
		printf("No enough memory space for page frame number to insert!\n");
		return -1;
	}

	*data = frame_number;

	/* fee(insert) a frame number to free page frame list head */
	if (list_ins_next(frame, NULL, data) != 0) {
		printf("No enough memory space for free page frame list!\n");
		return -1;
	}

	return 0;
}

void destory_frame(void *data)
{
	/* alloc_frame used free() to free page frame head pointer */
	free(data);
}

int create_frame(Plist *L, int n)
{
	unsigned int j, *data;

	*L = (Plist)malloc(sizeof(List));
	if (!L) {
		printf("Cant create free page frame list, no memory space!\n");
		exit(-1);
	}

	init_page_frame_list(L, destory_frame);

	for (j = 0; j < n; j ++) {
		/* Insert the (&j + i) to simluate page frame number */
		data = &j + j;
		if (list_ins_next(*L, NULL, data) != 0) {
			printf("Free %d page frame add to page frame list, hit no space!\n", j);
			exit(-1);
		}
	}

	return 0;
}

int main (int argc, char *argv[])
{

	int n = 5, ret, page_frame;
	Plist L;

	ret = create_frame(&L, n);
	print_list(L);

#if 0
	ret = alloc_frame(L);
	print_list(L);

	ret = free_frame(L, page_frame);
	print_list(L);

	destory_page_frame_list(&L);
	free(L);
#endif
	return ret;
}
