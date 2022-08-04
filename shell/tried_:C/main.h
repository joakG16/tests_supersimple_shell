#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *name);

char *_strdup(char *str);
char **getdirectories(void);
int countdirs(char *path);
char *str_concat(char *s1, char *s2);
char **dirtokens(void);

#endif
