/*
  TAREA 1
  Alumno: Arturo Yepez 15-11551
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para salir del programa.

// Funciones que debe recibir
#include "linkedList.h"

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

    // Maneja el caso en que no haya la cantidad minima necesaria de argumentos.
    if (argc < 2) {
        printf("ERROR: No se encontro el nombre del archivo.\n");
        return -1;
    }

    // Se crea un ciclo que recorra el archivo y vaya agregando todos los archivos
    int i = 2;

    // Comprueba la cantidad de archivos por abrir
    if (argc - 2 == *argv[1]) {
        printf("ERROR: El numero de archivos en el argumento no coincide con la cantidad de archivos por recorrer.\n");
        exit(1);
    }

    // Inicializa la lista
    node head = NULL;

    // Comienza el recorrido entre los archivos
    while (i < argc) {
        // Se abre el archivo que se desea contabilizar
        FILE *file = fopen(argv[i], "r");

        // Si el archivo no existe o no puede leerse salta una excepcion
        if(file == NULL) {
            exit(1);
        }

        // Se inicializa la variable del buffer con la que se 
        char buffer[100];

        while(fscanf(file, "%s[^\n]", buffer) != EOF) {
            addNode(&head, buffer);
        }

        // Cierra el archivo que se tenia abierto
        fclose(file);
        i++;
    }

     // Ordena la lista y luego la imprime
    sortList(head);
    printList(&head);

    exit(0);
}