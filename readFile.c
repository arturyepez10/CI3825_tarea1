#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

/*
* Funcion: readFile
* --------------------------
* Procesa un archivo y retorna lo escrito dentro de este.
* 
* name: El nombre del archivo donde estan las palabras a contabilizar.
*
* return: un arreglo de strings donde cada entrada sera una linea del archivo.
*/

// A modo de ejemplo, la funcion solo se encarga de abrir un archivo y verificar que no sea vacio
void readFile(char *name) {
    // Se encarga de obtener y concatenar el nombre del archivo de texto
    char filename[MAXLINE];
    strcpy(filename, name);
    strcat(filename, ".txt");

    printf("'%s' is the name of the txt file\n", filename);
}