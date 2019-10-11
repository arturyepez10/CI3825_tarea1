# TAREA 1 DE CI3825 - SISTEMAS DE OPERACION 1

**Alumno:** Arturo Yepez
**Carnet:** 15-11551

Familiarizarse con los aspectos basicos de programacion en lenguaje C.

Desarrollar un programa que cuente el número de apariciones de cada palabra en un conjunto de archivos de texto. El programa recibe los nombres de los archivos por línea de comando e imprime por pantalla cada palabra y el número de apariciones, imprimiendo primero las palabras más frecuentes, en caso de palabras con la misma frecuencia imprimir en orden alfanumérico.

## IMPLEMENTACION

Se preocedera a dividir el trabajo en los siguientes archivos que tengan funciones para su uso luego:
* `linkedList` contiene las funciones asociadas al manejo de una Lista Simplemente Enlazada.
* `main` archivo principal que es donde se manejan las llamadas a linkedList y se maneja el archivo a ser leido.

La solucion se planteo de la siguiente manera: En el archivo `main.c` se itera sobre los argumentos que se le pasan al programa. Con cada argumento se abre un archivo, se leen todas las lineas y por cada linea leida se agrega un nodo a la Lista Simplemente Enlazada. 

Luego de iterar sobre todos los argumentos, haber leido todas las lineas de todos los archivos tenemos una lista enlazada con todos los valores y la cantidad de veces que se repiten, se procede a llamar al metodo encargado de hacer un Sort sobre los nodos de la lista actualmente creada. Al final, se  imprime la lista ordenada en conjunto con el contador de la cantidad de veces que se repite la palabra.