#include "../trim.h"
#include <stdlib.h>

int
main(void)
{
	char string[] = "               A   B C D      E F  ";
	//char string[] = "ABCDEF";

	puts(ltrim(string));
	puts(rtrim(string));
	puts(trim(string));

	puts("");
	for (int i=0; i<sizeof(string); i++)
		printf("%d ", string[i]);

	puts("");
	return 0;
}
