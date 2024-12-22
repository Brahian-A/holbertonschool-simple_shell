#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[69];
	int i, status, found;
	pid_t hijo;
	comando_t *comandos;
	char *comando_con_ruta;

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
		
		if (!found)
		{
			comando_con_ruta = buscar_path(args[0]);
			if (comando_con_ruta != NULL)
			{
			
				fprintf(stderr, "Comando no encontrado: %s\n", args[0]);
				continue;
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
				perror ("error al crear el proceso");
			}
		}
	}

	if (feof(stdin))
		printf("\nEOF detectado. Saliendo...\n");

	free(line);
	return 0;
	
}

