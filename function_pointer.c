#include "main.h"

/**
 *
 *
 *
 *
 */

comando_t *function_pointer(void)
{

	static comando_t comandos[] = {
		{"ls", comando_ls},
		{"pwd",comando_pwd},
		{"l", comando_ls},
		{"cd", comando_cd},
		{"exit", comando_exit},
		{NULL, NULL}
	};
	return(comandos);
}
