#include<stdio.h>
#include<unistd.h>


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
