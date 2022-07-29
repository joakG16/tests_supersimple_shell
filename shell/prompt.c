#include "stdio.h"
#include <stdlib.h>

int main()
{
	char *buffer;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("no buffer allocated");
		exit (1);
	}
	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
	free(buffer);
	return (0);
}
