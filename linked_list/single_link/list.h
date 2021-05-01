#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


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
void print_list(List**);
void clear_list(List**);

