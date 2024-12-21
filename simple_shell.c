#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[69];
	int i, status, found;
	pid_t hijo;
	comando_t *comandos = function_pointer();

	while (printf("$ "), getline(&line, &len, stdin) != -1)
	{
		line[strcspn(line, "\n")] = '\0';	

		if (*line == '\0')
			continue;

		i = 0;
		args[i] = strtok(line, " ");
		while (args[i] != NULL)
			args[++i] = strtok(NULL, " ");
		
		found = 0;
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
		
			hijo = fork();
			if (hijo == 0)
			{
				if (execve(args[0], args, NULL) == -1)
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

