#include "main.h"

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
