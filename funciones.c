#include "main.h"

/**
 *comando_ls -Ejecuta el comando ls para listar el contenido de un directorio
 *@args: Argumentos del comando ls (se pasa como array de cadenas)
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
*comando_cd - Cambia el directorio de trabajo usando el comando `cd`
*@args: Argumentos del comando cd donde args[1] es el directorio al que cambiar
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
 *comando_exit - Sale de la shell
 *@args: Argumentos del comando `exit` (aunque no se usa en este caso)
 */

void comando_exit(char **args)
{
	(void)args;
	printf("Saliendo del programa...\n");
	exit(0);
}
/**
 *comando_pwd - Muestra el directorio de trabajo actual
 *@args: Argumentos del comando `pwd` (no se usa en este caso)
 */
void comando_pwd(char **args)
{
    char directorio[1024];

    (void)args;

    if (getcwd(directorio, sizeof(directorio)) != NULL)
    {
        printf("%s\n", directorio);
    }
    else
    {
        perror("pwd");
    }
} 

/**
 *comando_clear - Limpia la terminal.
 *@args: Argumentos de la línea de comando(no se utilizan en este caso).
 */

void comando_clear(char **arg)
{
	pid_t hijo;

	hijo = fork();
	if (hijo == 0)
	{
		execvp("/bin/clear", arg);
		perror("Error ejecutando clear");
		exit(EXIT_FAILURE);
	}
	else if (hijo > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Error al crear el proceso");
	}
}
