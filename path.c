#include "main.h"

/**
 *
 *
 *
 *
 */

char *buscar_path(char *comando)
{
	char *path = getenv("PATH");
	char *directorio;
	char *comando_con_ruta = malloc(1024);
	struct stat buffer;

	if (comando[0] == '/')
	{
		return (comando);
	}

	directorio = strtok(path, ":");}
	while (directorio != NULL)
	{
		snprintf(comando_con_ruta, 1024, "%s/%s", directorio, comando);
		if (stat(comando_con_ruta, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			return comando_con_ruta;
		}

		directorio = strtok(NULL, ":");
	}

	free(comando_con_ruta);
	return (NULL);
}
