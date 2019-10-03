#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para salir del programa.

// Funciones que debe recibir
#include "readFile.h"

// Se define el maximo de lineas que puede tener un 
#define MAXLINE 1024

/*
* Funcion: MAIN
* --------------------------
* Controla todos los procesos que ocurren para poder entregar una lista con
  todos las palabras repetidas y la cantidad de veces que se repiten. 
 
* argc: La cantidad de argumentos pasados en la llamada realizada por linea
  de comandos.
* argv: Es un arreglo con todos los elementos que se pasaron en la llamada
  por linea de comandos.

* return: el entero 0, que significa la terminacion del programa.
*/

int main(int argc, char *argv[]) {

    // Maneja el caso en que no haya la cantidad necesaria de argumentos.
    if (argc != 2) {
        printf("ERROR: No se encontro el nombre del archivo.\n");
        return 0;
    }

    // Llama a la funcion que lee el archivo de texto.
    char hola[MAXLINE];
    strcpy(hola, argv[1]);
    readFile(hola);

    return 0;
}