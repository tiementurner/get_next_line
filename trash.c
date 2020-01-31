#include <stdlib.h>

void function(char **string)
{
	int i = 0;

	while (i < 2)
	{
		*string++;
		i++;
	}
}

int main()
{
	char *string;
	int i;
	string = (char *)malloc(sizeof(char) * 5);
	string[4] = '\0';
	string[0] = 'h';
	string[1] = 'a';
	string[2] = 'l';
	string[3] = 'o';
	function(&string);
	printf("%d,   %s\n", i, string);
}