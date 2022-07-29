#include <stdio.h>
#include <>

int main(void)
{
	int status;
	pid_t pid;
	int i;
	char *line, *buffer;
	char **artgv;
	size_t buff_size = 32;

	buffer = malloc(buff_size * sizeof(char));
	if (buffer == NULL)
	{
		perror("Error");
		return (1);
	}
	printf("#C
