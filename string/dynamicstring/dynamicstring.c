#include "dynamicstring.h"

char *
new_string(void)
{
	return calloc(sizeof(char), sizeof(char));
}

char *
append_string(char **dest, const char *value)
{
	if (*dest == NULL)
		return NULL;

	size_t len_value = strlen(value);
	size_t len_dest = strlen(*dest);

	char *tmp = realloc(*dest, (strlen(*dest) + len_value) +1);
	if (tmp == NULL)
		return *dest;

	strncat(tmp, value, len_value);
	tmp[len_value + len_dest] = '\0';

	return tmp;
}

char *
insert_string(char **dest, const char *value,
		size_t position)
{
	if (*dest == NULL)
		return NULL;

	size_t len_dest = strlen(*dest);
	size_t len_value = strlen(value);
	char *p_dest = *dest;

	if (position > len_dest)
		position = len_dest;

	char *tmp = calloc(sizeof(char), (len_dest + len_value) +1);
	if (tmp == NULL)
		return *dest;

	strncat(tmp, p_dest, position);
	strncat(tmp, value, len_value);
	strncat(tmp, p_dest + position, len_dest - position);

	free(*dest);

	return tmp;
}

char *
slice_string(char **dest, size_t start, size_t end)
{
	if (*dest == NULL)
		return NULL;

	size_t len = strlen(*dest);
	if (end > len)
		end = len;
	if (start > len)
		start = 0;

	len = end - start;
	char *tmp = calloc(sizeof(char), len +1);
	if (tmp == NULL)
		return *dest;

	strncpy(tmp, (*dest) + start, len);
	free(*dest);

	return tmp;
}


