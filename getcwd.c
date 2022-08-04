#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// This program places the name of the current directory in the
// buffer array, then displays the name of the current directory
// on the screen. Passing NULL as the buffer forces getcwd to allocate
// memory for the path, which allows the code to support file paths
// longer than _MAX_PATH, which are supported by NTFS.

int main(void)
{
	char *cwd = NULL;

	cwd = getcwd(NULL, 0);

	printf("%s\n", cwd);

	free(cwd);

	return (0);
}
