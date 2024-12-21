#include "main.h"

/**
 *
 *
 *
 *
 */

void comando_ls(char **args)
{
	pid_t hijo;
	int status;

	hijo = fork();
	if (hijo == 0)
	{
		if (execve("/bin/ls", args, NULL) == -1)
		{
			perror("Error ejecutando ls");
			exit(EXIT_FAILURE);
		}
	}
	else if (hijo > 0)
	{
		wait(&status);
	}
	else
	{
		perror("Error al crear el proceso para ls");
	}
}



/**
*
*
*
*
*/



void comando_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "Shell_Error: falta argumento para cd\n");
    }
    else if (chdir(args[1]) != 0)
    {
        perror("Error al cambiar de directorio");
    }
}


/**
 *
 *
 *
 *
 */

void comando_exit(char **args)
{
	printf("Saliendo del programa...\n");
	exit(0);
}
