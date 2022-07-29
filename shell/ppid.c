#include "stdio.h"
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_p_pid;

	my_p_pid = getppid();
	printf("%u\n", my_p_pid);
	return (0);
}
