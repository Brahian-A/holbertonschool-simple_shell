#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[] = {NULL};

	while (69)
	{
		printf("$ ");


		if (getline(&line, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				printf("\nEOF detectado. Saliendo...\n");
				break;
			}
			else
			{
                	perror("Error");
                	break;
			}
		}


	line[strcspn(line, "\n")] = '\0';

	if (strcmp(line, "exit") == 0)
	{
		printf("Saliendo del programa...\n");
		break;
	}

if (strcmp(line, "ls") == 0 || (strcmp(line, "l") == 0))
{
	excave (/bin/bash/ls)

	if (*line == '\0')
	continue;


	printf("Comando ingresado: %s\n", line);


	}

	free(line);
	return 0;
}
