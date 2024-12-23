#include "main.h"

/**
 *main - Función principal de la shell personalizad
 *Return: 0 en caso de éxito, otro valor en caso de erro
 */

int main(void)
{
	size_t len = 0;
	char *args[69], *line = NULL;
	int i, found;
	comando_t *comandos;

	while (printf("$ "), getline(&line, &len, stdin) != -1)
	{
		tokenizar(line, args);

		if (args[0] == NULL)
			continue;

		found = 0;
		comandos = function_pointer();
		for (i = 0; comandos[i].comando != NULL; i++)
		{
			if (strcmp(args[0], comandos[i].comando) == 0)
			{
				comandos[i].funcion(args);
				found = 1;
				break;
			}
		}

		if (found == 0)
			no_encontrado(args);
	}
	if (feof(stdin))
		printf("\nEOF detectado. Saliendo...\n");

	free(line);
	return (0);

}

/**
 *no_encontrado - maneja la ejecución de comandos no encontrado
 *@args: arreglo de argumentos ingresados por el usuario
 *
 */


void no_encontrado(char **args)
{
	char *comando_con_ruta;
	pid_t hijo;
	int status;

	comando_con_ruta = buscar_path(args[0]);
	if (comando_con_ruta == NULL)
	{

		fprintf(stderr, "Comando no encontrado: %s\n", args[0]);
		return;
	}

	hijo = fork();
	if (hijo == 0)
	{
		if (execve(comando_con_ruta, args, NULL) == -1)
		{
			perror("Shell: Comando no encontrado");
			exit(EXIT_FAILURE);
		}
	}

	else if (hijo > 0)
	{
		wait(&status);
	}
	else
	{
		perror("error al crear el proceso");
	}
}
