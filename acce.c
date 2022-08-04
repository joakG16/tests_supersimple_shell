#include<stdio.h>
#include<unistd.h>

// This program places the name of the current directory in the
// buffer array, then displays the name of the current directory
// on the screen. Passing NULL as the buffer forces getcwd to allocate
// memory for the path, which allows the code to support file paths
// longer than _MAX_PATH, which are supported by NTFS.

int main(void)
{
    if( access( "/bin/ls", F_OK ) != -1)
    {
        printf("file is found\n");
    }
    else
    {
    printf("file is not found\n");
    }
    return 0;
}
