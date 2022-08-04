#include <stdio.h>

int countm(char *str);

/**
 *
 *
 *
 */
int countm(char *str)
{
	int i;
	size_t count = 0;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 && (str[i + 1] == 32 || str[i + 1] == '\0'))
		{
			i++;
			continue;
		}
		else
		{
			count++;
			i++;
		}
	}
	return(count);
}
int main(void)
{
	char *string = "d     hello my name is sksksksk      qs";
	int i = countm(string);

	printf("%d\n", i);

	return(0);
}
