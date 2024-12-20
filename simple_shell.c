#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[69];
	int i, status;
	pid_t hijo;
	
	while (printf("$ "), getline(&line, &len, stdin) != -1)
	{
		line[strcspn(line, "\n")] = '\0';	

		if (*line == '\0')
			continue;

		i = 0;
		args[i] = strtok(line, " ");
		while (args[i] != NULL)
			args[++i] = strtok(NULL, " ");
		
		if (strcmp(args[0], "cd") == 0)
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
		else if (strcmp(args[0], "exit") == 0)
		{
			printf("Saliendo del programa...\n");
			break;
		}


		else
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

