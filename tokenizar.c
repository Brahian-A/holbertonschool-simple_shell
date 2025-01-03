#include "main.h"

/**
 *tokenizar - Divide una cadena en tokens (argumentos)
 *@line: La línea de entrada que contiene los argumentos
 *@args: Un arreglo de punteros donde se almacenarán los tokens
 * Return: El número de tokens (argumentos) encontrados
 */



int tokenizar(char *line, char *args[])
{
	int i = 0;

	line[strcspn(line, "\n")] = '\0';

	args[i] = strtok(line, " ");
	while (args[i] !=  NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	return (i);
}

