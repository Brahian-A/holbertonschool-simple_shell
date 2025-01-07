#include "main.h"

/**
 *obtener_path - Busca y devuelve el valor de la variable PATH en el entorno.
 *@envp: Matriz de cadenas que representa las variables de entorno.
 *Return: Puntero a la cadena que contiene el valor de PATH,
 */

char *obtener_path(char *envp[])
{
	int i = 0;

	while (envp[i] != NULL) /*el while recorre cada elemento de envp que es una array que contiene todas las variables de entorno hasta llegar a la ultima  */
	{
		if (strncmp(envp[i], "PATH=", 5) == 0) /* compara en que posicion de envp esta y si es igual a path  */
		{
			return (envp[i] + 5); /*si encuentra la variable path devuelve la cadena que comienza justo dsp de path, que es el valor real de path  */
		}
		i++; /*si no encontro path, se incrementa i++ para seguir a la siguiente variable de entorno */
	}
	return (NULL); /* si no enconto path en ninguna parte del arreglo, retorna null */
}


/**
 *buscar_path - Busca un comando en los directorios del PATH
 *@comando: Nombre del comando a buscar
 *Return: Ruta completa del comando si se encuentra, NULL si no se encuentra
 */

char *buscar_path(char *comando, char *envp[]) /* comando es el nombre del comado que estamos buscando, y envp es el arreglo de variables de entorno */
{
	char *comando_ruta, *direct, *path_copy = NULL, *path = obtener_path(envp); /* y luego se declaran las variables comando_ruta para almacenar la ruta completa del comando , direct, para almacenar los directorios individuales, path copy, que es una copia del valor de path para evitar modificar el original, y luego tenemos la variable path, que es igual a la funcion obtner path  */
	struct stat buffer; /* una variable de tipo struct que guarda informacion del archivo */

	if (comando[0] == '/') /*verifica si el comando dado ya tiene la ruta absoluta(si tiene la barra es que tiene la ruta completa ) */
	{
		if (stat(comando, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) /*usa stat para verificar si el archivo especificado en comando existe y si es ejecutable */
		{
			return (comando); /* si ya existe y es ejecutable rtorna comando (ruta completa) */
		}
		return (NULL); /* si no existe o no es ejecutable retorna null */
	}

	path_copy = strdup(path); /*lo q hace es igualar path copy a una copia de path   */ 
	if (path_copy == NULL) /* si path copy = null tira error duplicando path  */
	{
		perror("Error duplicando PATH");
		return (NULL);
	}
	comando_ruta = malloc(1024); /* reserva memoria para la variable comando ruta */
	if (comando_ruta == NULL) /* si es igual a null, retorno error asignando memoria */
	{
		perror("Error asignando memoria");
		free(path_copy); /* y libero la memoria */
		return (NULL); /*y como dio error retorna null  */
	}
	direct = strtok(path_copy, ":"); /*usa strtok para dividir la cadena path copy en tokens */ 
	while (direct != NULL) /*el while recorre cada directorio de path obtenido por strtok */
	{
		if (ruta(direct, comando, comando_ruta, &buffer)) /* llama a la funcion ruta pasando el directorio actual direct, el comando buscar comando, la variable comando_ruta,( para almacenar la ruta completa )y buffer para verificar la existencia del archivo */
		{
			free(path_copy);  /* si se encuentra la ruta del comando en uno de los directorios de path se libera la memoria de path copy */
			return (comando_ruta); /* y se retorna comando_ruta */
		}
		direct = strtok(NULL, ":"); /* continua al siguiente siguiente directorio de path */
	}
	free(comando_ruta); /* si no se encuentra el comando en ningun directorio de path, se libera la memoria  */
	free(path_copy); /* se libera path copy */
	return (NULL); /* cunado se libera path copy se retorna null */
}

/**
 *ruta- Intenta construir la ruta del comando
 *@direct: El directorio a verificar
 *@comando: El nombre del comando a buscar
 *@comando_ruta: La ruta completa del comando
 *@buffer: Buffer para verificar la existencia del comando
 *Return: 1 si el comando se encuentra, 0 si no
 */

int ruta(char *direct, char *comando, char *comando_ruta, struct stat *buffer) /* direct es el directorio en el q se busca el comando ,comando es el nombre del comando a buscar, y comando_ruta es el espacio donde se almacena la ruta completa del comando y buffer es un struct de tipo stat para almacenar informacion del archivo */
{
	snprintf(comando_ruta, 1024, "%s/%s", direct, comando); /*costruye la ruta completa del comando conectando el directorio direct con el nombre del comando */
	return (stat(comando_ruta, buffer) == 0 && (buffer->st_mode & S_IXUSR)); /* usa stat para verificar si el archivo existe en esa ruta, que es comando_ruta, y si es ejecutable */
}
