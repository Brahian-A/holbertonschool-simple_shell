#include "main.h"

/**
 *buscar_path - Busca un comando en los directorios del PATH
 *@comando: Nombre del comando a buscar
 *Return: Ruta completa del comando si se encuentra, NULL si no se encuentra
 */

char *buscar_path(char *comando)
{
	char *comando_ruta, *direct, *path_copy = NULL, *path = getenv("PATH");
	struct stat buffer;

	if (comando[0] == '/')
	{
		if (stat(comando, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			return (comando);
		}
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Error duplicando PATH");
		return (NULL);
	}
	comando_ruta = malloc(1024);
	if (comando_ruta == NULL)
	{
		perror("Error asignando memoria");
		free(path_copy);
		return (NULL);
	}
	direct = strtok(path, ":");
	while (direct != NULL)
	{
		if (ruta(direct, comando, comando_ruta, &buffer))
		{
			free(path_copy);
			return (comando_ruta);
		}
		direct = strtok(NULL, ":");
	}
	free(comando_ruta);
	free(path_copy);
	return (NULL);
}

/**
 *ruta- Intenta construir la ruta del comando
 *@direct: El directorio a verificar
 *@comando: El nombre del comando a buscar
 *@comando_ruta: La ruta completa del comando
 *@buffer: Buffer para verificar la existencia del comando
 *Return: 1 si el comando se encuentra, 0 si no
 */

int ruta(char *direct, char *comando, char *comando_ruta, struct stat *buffer)
{
	snprintf(comando_ruta, 1024, "%s/%s", direct, comando);
	return (stat(comando_ruta, buffer) == 0 && (buffer->st_mode & S_IXUSR));
}
