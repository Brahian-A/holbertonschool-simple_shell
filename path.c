#include "main.h"

/**
 *buscar_path - Busca un comando en los directorios del PATH
 *@comando: Nombre del comando a buscar
 *Return: Ruta completa del comando si se encuentra, NULL si no se encuentra
 */

char *buscar_path(char *comando)
{
	char *path = getenv("PATH");
	char *comando_con_ruta, *directorio, *path_copy = NULL;
	struct stat buffer;

	if (comando[0] == '/')
	{
		if (stat(comando, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{	
			free(path_copy);
			return (comando);
		}
		else
		{
			free(path_copy);
			return (NULL);			
		}
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Error duplicando PATH");
		return (NULL);
	}
	comando_con_ruta = malloc(1024);
	if (comando_con_ruta == NULL)
	{
		perror("Error asignando memoria");
		free(path_copy);
		return NULL;
	}

	directorio = strtok(path, ":");
	while (directorio != NULL)
	{
		snprintf(comando_con_ruta, 1024, "%s/%s", directorio, comando);
		if (stat(comando_con_ruta, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return comando_con_ruta;
		}

		directorio = strtok(NULL, ":");
	}

	free(comando_con_ruta);
	free(path_copy);
	return (NULL);
}
