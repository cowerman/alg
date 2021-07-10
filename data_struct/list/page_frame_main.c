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
		/* command this: if the data use malloc, it should use free */
		//free(data);
	}

	return frame_number;
}

int free_frame(Plist frame, int *frame_number)
{
	int *data = frame_number;
	
	//data = (int *)malloc(sizeof(int));
	//if (!data) {
	//	printf("No enough memory space for page frame number to insert!\n");
	//	return -1;
	//}

	data = frame_number;
	printf("free number:0x%x, data:%p\n", *frame_number, data);

	/* free(insert) a frame number to free page frame list head */
	if (list_ins_next(frame, NULL, data) != 0) {
		printf("No enough memory space for free page frame list!\n");
		return -1;
	}

	//free(data);
	return 0;
}

void destory_frame(void *data)
{
	/* use free() to free the list which alloced in create_frame */
	//free(data);
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
		data = (unsigned int *)malloc(sizeof(unsigned int));
		if (!data) {
			printf("No space!\n");
			exit(-1);
		}
		*data = j;
		printf("The added meta data:%p\n", data);
		if (list_ins_next(*L, NULL, data) != 0) {
			printf("Free %d page frame add to page frame list, hit no space!\n", j);
			destory_page_frame_list(L);
			exit(-1);
		}
	}

	return 0;
}

int main (int argc, char *argv[])
{

	int n = 5, ret, page_frame;
	Plist L;

	printf("-----create free page frame list-------\n");
	ret = create_frame(&L, n);
	print_list(L);

	printf("-----alloc frame number from free page frame list-------\n");
	page_frame = alloc_frame(L);
	printf("Get the page frame number:%d\n", page_frame);
	print_list(L);

	printf("-----free page frame number:%d to list-------\n", page_frame);
	ret = free_frame(L, &page_frame);
	print_list(L);

	printf("-----destory free page frame list-------\n");
	destory_page_frame_list(&L);
	free(L);

	return ret;
}
