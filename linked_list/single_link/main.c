#include <stdio.h>
#include "list.h"

void
print_list(List **N)
{
	List *tmp = *N;
	while (tmp != NULL) {
		printf("%s ", (char*)tmp->data);
		tmp = tmp->next;
	}
	puts("");
}

int
main(void)
{
	List *N = new_list();

	N = append_list(&N, (char*)"hello ");
	N = insert_list(&N, (char*)"well ", 0);
	N = append_list(&N, (char*)"world ");
	N = insert_list(&N, (char*)"hmm ", 0);

	printf("size list: %lu\n", get_size_list(&N));
	/*

	print_list(&N);
	N = insert_list(&N, (char*)", ", 1);
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

