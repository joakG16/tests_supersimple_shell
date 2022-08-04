#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void)
{
	int status;
	pid_t pid;
	int i;
	char *line, *buffer;
	char **argv;
	size_t buff_size = 32;

	buffer = malloc(buff_size * sizeof(char));
	if (buffer == NULL)
	{
		perror("Error");
		return (1);
	}
	printf("#cisfun$ ");
	getline(&buffer, &buff_size, stdin);
	printf("'%s'", buffer);
	argv = malloc(2 * sizeof(char*));
	if (argv == NULL)
	{
		perror("Error");
		return (1);
	}
	argv[0] = malloc((strlen(buffer)) * sizeof(char));
	if (argv[0] == NULL)
	{
		perror("Error");
		return (1);
	}
	strcpy(argv[0], buffer);
	argv[1] = NULL;
	printf("'%s'", argv[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(buffer);
		free(argv[0]);
		free(argv);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			free(argv);
			free(argv[0]);
			free(buffer);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
