#pragma once

#include <stdlib.h>


typedef struct __attribute__((packed)) List_t {
	void *data;
	struct List_t *next;
} List;

List *new_list(void);
List *append_list(List**, void*);
List *insert_list(List**, void*, size_t);
void delete_last_list(List**);
void delete_at_list(List**, size_t);
size_t get_size_list(List **list);
void clear_list(List**);

