#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void);

extern char **environ;

char *_getenv(const char *name);

#endif
