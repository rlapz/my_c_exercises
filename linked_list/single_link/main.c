#include <stdio.h>
#include "list.h"


int
main(void)
{
	List *N = new_list();

	N = append_list(&N, (int8_t*)"hello ");
	N = insert_list(&N, (int8_t*)"well ", 0);
	N = append_list(&N, (int8_t*)"world ");
	N = insert_list(&N, (int8_t*)"hmm ", 0);

	printf("size list: %lu\n", get_size_list(&N));
	/*

	print_list(&N);
	N = insert_list(&N, (int8_t*)", ", 1);
	print_list(&N);
	delete_last_list(&N);
	*/
	print_list(&N);
	delete_last_list(&N);
	print_list(&N);
	delete_at_list(&N, 0);
	print_list(&N);
	delete_at_list(&N, 2);
	print_list(&N);

	printf("size list: %lu\n", get_size_list(&N));

	clear_list(&N);

	return 0;
}

