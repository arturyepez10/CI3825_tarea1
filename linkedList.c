#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  DESCRIPTORES DE LOS NODOS DE LA LISTA ENLAZADA
*/
struct linkedList {
    char *word;
    int counter;
    struct linkedList *next;
};

// Define la estructura de la Lista Simplemente enlazada y agrega un alias
typedef struct linkedList *node; 


/*
* Funcion: createNode
* --------------------------
* Crea un nodo nuevo vacio.

* return: Un nodo nuevo vasio sin ningun valor ni apuntador.
*/

node createNode(){
    // Declara un nuevo nodo, con el alias que se creo
    node temp;

    // Al nodo se le asigna una cantidad de memoria
    temp = (node)malloc(sizeof(struct linkedList));
    
    // Se asigna NULL a los valores del nodo
    (*temp).word = NULL;
    (*temp).counter = 0;
    (*temp).next = NULL;
    
    return temp;
}

/*
* Funcion: search
* --------------------------
* Hace una busqueda por toda la lista para encontrar el nodo con cierta palabra.

* head: Es el primer nodo de la lista.

* word: La palabra principal de cada nodo que se quiere buscar.

* return: Nodo a encontrar o NULL en caso de no encontrar nodo.
*/

node search(node head, char *word) {
    node p;
    p = head;
    while (p != NULL) {
        if (strcmp((*p).word, word) == 0) {
            return p;
        }
        p = (*p).next;
    }
    return NULL;
}

/*
* Funcion: addNode
* --------------------------
* Es la funcion encargada de agregar un nodo a la lista enlazada
  luego de ser inicializada.

* head: Es el primer nodo de la lista.

* word: Palabra que llevara el nodo como dato.

* return: Retorna de nuevo la cabeza de la Lista enlazada
*/

node addNode(node *head, char *word) {
    // Se declaran dos nodos: temp y p
    node temp,p;

    char *storedWord = malloc(100 * sizeof(char));
    strcpy(storedWord, word);

    // Suma al contador la cantidad de apariciones de la palabra en la lista
    node repeated = search(*head, storedWord);
    if (repeated != NULL) {
        (*repeated).counter += 1;
        return *head;
    }

    // Creamos el nodo y los contenidos de este los inicializamos vacios
    temp = createNode();

    // Asignamos datos correspondientes al nodo creado
    (*temp).word = storedWord;
    (*temp).counter += 1;

    // Cuando la lista esta vacia asigna como cabeza el nuevo
    if (*head == NULL) {
        *head = temp;
    } else {
        p  = *head;

        // Se recorren todos los nodos hasta que se llegue al ultimo nodo y se asigna el nuevo nodo recien creado        
        while((*p).next != NULL) {
            p = (*p).next;
        }
        (*p).next = temp;
    }
    return *head;
}

/*
* Funcion: printNode
* --------------------------
* Imprime unico seleccionado de la Lista Enlazada.

* Node: Nodo de la lista que se desea imprimir.

* return: void.
*/

void printNode(node Node) {
    // Se inicializa una variabe del tipo nodo.
    node p;

    // Asignado el respectivo nodo a imprimir.
    p = Node;

    // Se imprimen datos del nodo.
    printf("%s %i\n", (*p).word, (*p).counter);
}

/*
* Funcion: printList
* --------------------------
* Imprime todos los nodos de la Lista Simplemente Enlazada.

* head: Es el primer nodo de la lista.

* return: void.
*/

void printList(node *head) {
    // Se inicializa una variabe del tipo nodo.
    node p;

    // Asignado la cabeza de la lista para manipulacion.
    p = *head;

    // Ciclo en el que se recorre la lista e imprimiendo exclusivamente los datos.
    while(p != NULL){
        printf("%s %i\n", (*p).word, (*p).counter);
        p = (*p).next;
    }
}


/*
* Funcion: sortList
* --------------------------
* Se encarga de ordenar todos los elementos de la Lista Simplemente
  Ordenada. Funciona por comparaciones y esta basado en el diseño de los
  sort de comparacion basicos.

* head: Es el primer nodo de la lista.

* return: void.
*/

void sortList(node head) {
    // Inicializados elementos para hacer swap de los datos
    int a;
    char *b;

    // Inicializado variables que llevaran los nodos a ser comparados.
    node temp1, temp2;

    temp1 = head;
    while (temp1 != NULL) {
        temp2 = (*temp1).next;
        while (temp2 != NULL) {
            if((*temp2).counter > (*temp1).counter) {
                // Swap de los datos (tanto palabra como contador)
                a = (*temp1).counter;
                b = (*temp1).word;
                (*temp1).counter = (*temp2).counter;
                (*temp1).word = (*temp2).word;
                (*temp2).counter = a;
                (*temp2).word = b;
            } 
            // Encargado de verificar si las palabras estan en orden alfabetico y ordernarlas por este
            if (strcmp((*temp1).word, (*temp2).word) > 0 && (*temp2).counter == (*temp1).counter) {
                b = (*temp1).word;
                (*temp1).word = (*temp2).word;
                (*temp2).word = b;
            }
            temp2 = (*temp2).next;
        }
        temp1 = (*temp1).next;
    }
}
