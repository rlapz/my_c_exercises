#include "trim.h"


/* left trim */
char *
ltrim(char *string)
{
	while (isspace(*string))
		string++;
	return (char*)string;
}

/* right trim */
char *
rtrim(char *string)
{
	char *end = string + strlen(string)-1;
	while (isspace(*end)) {
		*end = '\0';
		end--;
	}
	return string;
}

/* trim all */
char *
trim(char *string)
{
	char *p1 = string;
	char *p2 = p1;
	char c;
	int count = 0;
	while (*p1) {
		if (isspace(*p1)) {
			*p1 = '\0';
			p1++;
			count++;
			continue;
		}
		c = *p1;
		*p2 = c;
		p2++;
		if (count > 0)
			*p1 = '\0';
		p1++;
	}
	return string;
}

