#include "main.h"

/**
 *comando_cat - Muestra el contenido de un archivo
 *@args: Argumentos de la línea de comand
 */

void comando_cat(char **args)
{
	pid_t hijo;
	int status;

	(void)args;

	hijo = fork();
	if (hijo == 0)
	{
		if (execve("/bin/cat", args, NULL) == -1)
		{
			perror("Error ejecutando cat");
			exit(EXIT_FAILURE);
		}
	}
	else if (hijo > 0)
	{
		wait(&status);
	}

else
	{
		perror("Error en el proceso cat");
	}
}
