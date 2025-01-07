#include "main.h"

/**
 *main - Función principal de la shell personalizad
 *@argc: número de argumentos de la línea de comandosin usar
 *@argv: array de punteros a los argumentos de la línea de comandossin usar
 *@envp: array de punteros al entorno (sin usar directamente en esta función)
 * Return: 0 en caso de éxito, otro valor en caso de erro
 */

int main(int argc, char *argv[], char *envp[]) /*se define la funcion principal main */
{
	size_t len = 0;
	char *args[69], *line = NULL;
	int i, found;
	comando_t *comandos;

	(void)argc;
	(void)argv;
	(void)envp;

	while (69)
	{
		if (isatty(STDIN_FILENO)) /* para detectar la entrada del teclado */
			printf("$ ");

		if (getline(&line, &len, stdin) == -1) /* getline detecta la entrada del usuario, la almacena en line, despues almacena el largo en len, y eso en la terminal indicado por stdin , y si retorna -1 significa que hubo un error , ahi libera y sale */
		{
			free(line);
			break;
		}
		tokenizar(line, args); /* tokeniza */

		if (args[0] == NULL) /* si la entrada esta vacia , avanza */
			continue;

		found = 0; /* es para que se resete a 0 */
		comandos = function_pointer(); /* la variable comando la iguala a function pointer  */
		for (i = 0; comandos[i].comando != NULL; i++) /*ahi recorre la estructura, recorre comandos para encontrar el comando que escribio el usaurio */
		{
			if (strcmp(args[0], comandos[i].comando) == 0)/* el if compara el primer argumento con los comandos registrados */
			{
				comandos[i].funcion(args); /* si hay coincidencia, llama a la funcion correspontiente */
				found = 1; /* si hay coinidencias osea que encontro el comando, found pasa a ser 1 , y se sale */
				break;
			}
		}
		if (found == 0)
			no_encontrado(args, envp); /* si found = 0 ejecuta la funcion no_encontrado */

		free(line); /* si no lo encuentra libera la memoria */
		line = NULL; /* con line = NULL se resetea line */
	}
return (0);
}

/**
 *no_encontrado - maneja la ejecución de comandos no encontrado
 *@args: arreglo de argumentos ingresados por el usuario
 *@envp: array de punteros al entorno (sin usar directamente en esta función
 */


void no_encontrado(char **args, char *envp[]) 
{
	char *comando_con_ruta;
	pid_t hijo; /* hijo es el hijo del proceso hijo */
	int status; /* almacena el estado del proceso hijo */

	comando_con_ruta = buscar_path(args[0], envp); /* busca la ruta del comando con buscar path, si no la encuntra muestra error y termina la funcion */
	if (comando_con_ruta == NULL) /* aca detecta si hay error */
	{

		fprintf(stderr, "Comando no encontrado: %s\n", args[0]); /* entra aca si hay error  */
		return;
	}

	hijo = fork(); /*si no dio error, significa que existe el comando, con fork creamos el procesio hijo para ejecutarlo */
	if (hijo == 0) /* si hijo = 0 es que es el hijo */
	{
		if (execve(comando_con_ruta, args, envp) == -1) /* execve es una llamada al sistema que ejecuta el comando con ruta , si da -1 ejecuta el error de abajo   */
		{
			perror("Shell: Comando no encontrado");
			exit(EXIT_FAILURE);
		}
	}

	else if (hijo > 0) /*significa que no es el hijo, que es el padre */
	{
		wait(&status); /* con wait el padre queda esperando el procso hijo */
	}
	else
	{
		perror("error al crear el proceso");
	}
	if (comando_con_ruta != NULL)
	{
		free(comando_con_ruta);
		comando_con_ruta = NULL;
	}

}
