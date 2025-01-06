Simple Shell

Este proyecto es una implementación de una shell personalizada escrita en C. La shell permite ejecutar comandos básicos, como ls, pwd, cd, exit, entre otros, y ejecutar binarios en el sistema.

Características

Ejecutar comandos básicos como ls, pwd, cd, exit, y clear.

Manejo de errores y mensajes para comandos no encontrados.

Búsqueda de binarios usando el PATH del sistema.

Ejecución de múltiples argumentos y redirección al sistema operativo.

Archivos

main.c

Archivo principal que ejecuta la lógica principal de la shell:

Espera entrada del usuario.

Tokeniza la línea ingresada.

Busca el comando ingresado en una tabla de comandos predefinida.

Llama a la función correspondiente o intenta ejecutar un binario si no se encuentra en la tabla.

funciones.c

Contiene las funciones de los comandos principales:

comando_ls: Ejecuta el comando ls.

comando_cd: Cambia el directorio de trabajo.

comando_exit: Sale de la shell.

comando_pwd: Muestra el directorio de trabajo actual.

comando_clear: Limpia la terminal.

funciones2.c

Extensión de las funciones principales:

Implementa la lógica para manejar comandos no encontrados y ejecutar binarios directamente.

path.c

Contiene funciones para manejar la variable PATH y buscar rutas de comandos:

obtener_path: Obtiene el valor de la variable PATH.

buscar_path: Busca un comando en los directorios definidos en PATH.

ruta: Verifica la existencia y ejecutabilidad de un comando en una ruta específica.

function_pointer.c

Define una tabla de comandos predefinidos utilizando estructuras:

Tabla que asocia cada comando con su función respectiva.

tokenizar.c

Divide las líneas ingresadas en tokens:

tokenizar: Separa los argumentos de la línea de comandos ingresada.

main.h

Archivo de cabecera que define las funciones y estructuras utilizadas:

Define la estructura comando_t.

Declara todas las funciones utilizadas en los archivos anteriores.

Compilación

Utiliza el siguiente comando para compilar la shell:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Uso

Ejecuta la shell personalizada con el comando:

./hsh

La shell muestra un prompt ($) para que el usuario pueda ingresar comandos. Algunos ejemplos:

$ ls
$ pwd
$ cd ..
$ clear
$ cat archivo.txt
$ exit

Detalles Técnicos

Ejecución de comandos:

Los comandos se buscan primero en la tabla de comandos predefinidos.

Si no se encuentran, se busca en los directorios especificados por la variable PATH.

Manejo de errores:

Mensaje de error para comandos no encontrados.

Manejo de errores al cambiar directorios o ejecutar comandos no válidos.

Ejecución de procesos:

Utiliza fork, execve, y wait para manejar procesos hijos.

Requisitos del Sistema

Sistema operativo basado en Unix/Linux.

Compilador GCC.

Contribuciones

Si deseas contribuir a este proyecto, envía un pull request a través del repositorio en GitHub.

Autor

Proyecto desarrollado por Juandicode y brahian 
