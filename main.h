#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int tokenizar(char *line, char *args[]);
char *buscar_path(char *comando);
int ruta(char *direct, char *comando, char *comando_ruta, struct stat *buffer);
void no_encontrado(char **args);

/**
 *struct estructura- Estructura que asocia un comando con una funció
 * @comando: El nombre del comando.
 * @funcion: Puntero a la función que se ejecutar cuando se llame al comando.
 */

typedef struct estructura
{
	char *comando;
	void (*funcion)(char **args);
} comando_t;

comando_t *function_pointer(void);


void comando_ls(char **args);
void comando_cd(char **args);
void comando_exit(char **args);
void comando_pwd(char **args);
void comando_clear(char **args);
void comando_cat(char **args);
#endif
