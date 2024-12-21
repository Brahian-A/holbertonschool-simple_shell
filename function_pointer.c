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
		{"cd",comando_cd},
		{"exit", comando_exit},
		{NULL, NULL}
	};
	return(comandos);
}
