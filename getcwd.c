#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *cwd = NULL;

	cwd = getcwd(NULL, 0);

	printf("%s\n", cwd);

	free(cwd);

	return (0);
}
