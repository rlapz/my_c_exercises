#include <stdio.h>
#include <string.h>
#include "../dynamicstring.h"


int main(void)
{
	char* str = new_string();
	char* test = "Hello";

	str = append_string(&str, test);
	puts(str);
	str = append_string(&str, " world");
	puts(str);
	str = append_string(&str, " phew..");
	puts(str);
	str = slice_string(&str, 0, 11);
	printf("%s\n", str);
	str = insert_string(&str, "//.\\\\", 11);
	puts(str);
	str = insert_string(&str, "//.\\\\", 0);
	puts(str);
	free(str);

	return 0;
}
