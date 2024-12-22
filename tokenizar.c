#include "main.h"

/**
 *
 *
 *
 * 
 */



int tokenizar(char *line, char *args[])
{
	int i = 0;

	line[strcspn(line, "\n")] = '\0';

	args[i] = strtok(line, " ");
	while (args[i] !=  NULL)
	{
		i++;
		args[i] = strtok(NULL, " " );
	}
	return(i);
}

