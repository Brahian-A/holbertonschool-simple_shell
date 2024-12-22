#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int tokenizar(char *line, char *args[]);
char *buscar_path(char *comando);
char *buscar_path(char *comando);

typedef struct estructura
{
	char *comando;
	void (*funcion)(char **args);
}comando_t;

comando_t *function_pointer(void);


void comando_ls(char **args);
void comando_cd(char **args);
void comando_exit(char **args);


#endif
