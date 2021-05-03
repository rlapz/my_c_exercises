#ifndef DYNAMICSTRING_H
#define DYNAMICSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *new_string(void);
char *append_string(char **dest, const char *value);
char *insert_string(char **dest, const char *value,
		size_t position);
char *slice_string(char **dest, size_t start, size_t end);

#endif
