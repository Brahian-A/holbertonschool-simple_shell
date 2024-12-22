#include "main.h"

/**
 *function_pointer - Devuelve un puntero a una tabla de comandos
 *Return: un puntero a un arreglo de estructuras comando_t
 */

comando_t *function_pointer(void)
{

	static comando_t comandos[] = {
		{"ls", comando_ls},
		{"pwd", comando_pwd},
		{"l", comando_ls},
		{"cd", comando_cd},
		{"exit", comando_exit},
		{NULL, NULL}
	};
	return (comandos);
}
