#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 *
 */
char *_getenv(const char *name)
{
	int elem, index;
	bool are_equal;

	for (elem = 0; environ[elem] != NULL; elem++)
	{
		are_equal = true; /* seteado a 1, valor TRUE en condiciones */
		for (index = 0; environ[elem][index] != '='; index++)
		{
			if (name[index] != environ[elem][index])
			{
				are_equal = false;
				break; /* sigue al proximo elemento */
			}
		}

		if (are_equal)
		{
			/* si el valor es verdadero(comparacion exitosa),
			 * devuelve los valores luego del '=' 
			 */
			return (&environ[elem][index + 1]);
		}
	}
	return (NULL); /* en caso que no se halla encontrado nombre de la
			* variable pasada como argumento
			*/
}
/**
 *
 *
 *
 */
int main(void)
{
	char *path = NULL;
	char **dirs;
	char *toked;
	int i;

	path = malloc(sizeof(char) * 100);

	if(path == NULL)
		return (-1);

	path = _getenv("PATH");

	toked = strtok(path, ":");

	if(toked == NULL)
		return (-1);

	dirs = calloc(16, sizeof(char *));
	if (!dirs)
		return (-1);

	for(i = 0; i < 16 && toked != NULL; i++)
	{
		printf("%s\n", toked);
		dirs[i] = toked;
		toked = strtok(NULL, ":");
	}
	dirs[i] = NULL;


	return (0);
}

/**
 *
 *
 *
 */
int countdirs(char *path)
{
	int i, count = 1;

	for (i = 0; i < strlen(path) && path != NULL; i++)
	{
		if (path[i] == ':')
			count++;
	}
	return(count);
}
/**
 * _strdup - main
 * @str: string
 * Return: pointer to allocated memory
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0;
	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * strlen(str) + 1);
	if (s == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < (int)strlen(str); i++)
		{
			s[i] = str[i];
		}
		s[i] = '\0';
	}
	return (s);
}
/**
 *
 *
int main(int argc, char **argv)
{
	char *cwd = getcwd(NULL, 0);
	struct stat sb;
	char **dirs = malloc(sizeof(char*) * 7);
	int x, i;

	dirs = dirtokens();

	for (x = 0; dirs[x] != NULL; x++)
	{
		chdir(dirs[x]);
		if (stat(argv[1], &sb) == 0)
		{
			argv[1] = str_concat(dirs[x], argv[1]);
			if (argv[1] == NULL)
			{
				if (cwd)
					free(cwd);
				if (dirs)
				{
					for (i = 0; dirs[i] != NULL; i++)
						free(dirs[i]);
					free(dirs);
				}
				return (-1);
			}
			printf("found!\n");
			break;
		}
	}
	* change back to the dir. we were in and passes the newly created arg. *
	chdir(cwd);
	free(cwd);
	if (dirs[x] == NULL)
	{
		printf("not found\n");
		for (i = 0; dirs[i] != NULL; i++)
			free(dirs[i]);
		free(dirs);
		return (-1);
	}
	for (i = 0; dirs[i] != NULL; i++)
		free(dirs[i]);
	free(dirs);
	return (0);
}
*/
/**
 *
 *
 *
 */
char *str_concat(char *s1, char *s2)
{
	char *stcon;
	int i, j;

	stcon = malloc(sizeof(char) * strlen(s1) + strlen(s2) + 2);
	/* 2 for '/' and null terminator */

	if (stcon == NULL)
		return (NULL);

	for (i = 0, j = 0; s1 && s1[i] != '\0'; i++, j++)
	{
		stcon[j] == s1[i];
	}
	if (j != 0)
	{
		stcon[j] = '/';
		j++;
	}
	for (i = 0; s2 && s2[i] != '\0'; i++, j++)
	{
		stcon[j] == s2[i];
	}
	stcon[j] = '\0';

	/* s2 would be the command without path, no longer needed */
	if(s2)
		free(s2); 
	return(stcon);

}
