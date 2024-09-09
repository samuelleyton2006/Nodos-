#include <stdio.h>   // Incluye la biblioteca estándar de entrada y salida de C para usar funciones como printf y scanf.
#include <stdlib.h>  // Incluye la biblioteca estándar de C para gestión de memoria dinámica y otras funciones útiles como malloc y free.

// Definición de la estructura Nodo
typedef struct Nodo {        // Define una estructura llamada 'Nodo'.
    int dato;                // 'dato' es un campo que almacena un número entero.
    struct Nodo* siguiente;  // 'siguiente' es un puntero que apunta al siguiente nodo en la lista enlazada.
} Nodo;                      // 'Nodo' es un alias que se usa para declarar variables de tipo 'struct Nodo'.

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {               // Función que crea un nuevo nodo con el valor proporcionado.
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));  // Asigna memoria para un nuevo nodo en el heap y convierte el puntero devuelto por malloc a tipo 'Nodo*'.
    nuevoNodo->dato = valor;               // Asigna el valor pasado como argumento al campo 'dato' del nuevo nodo.
    nuevoNodo->siguiente = NULL;           // Inicializa el campo 'siguiente' como NULL porque el nodo no apunta a ningún otro nodo todavía.
    return nuevoNodo;                      // Devuelve un puntero al nuevo nodo creado.
}

// Función para añadir un nodo al principio de la lista
void agregarAlPrincipio(Nodo** cabeza, int valor) {  // Toma un puntero a la cabeza de la lista y un valor entero para añadir al principio.
    Nodo* nuevoNodo = crearNodo(valor);              // Crea un nuevo nodo con el valor proporcionado.
    nuevoNodo->siguiente = *cabeza;                  // El nuevo nodo apunta al nodo que antes era la cabeza.
    *cabeza = nuevoNodo;                             // Actualiza la cabeza de la lista para que sea el nuevo nodo.
}

// Función para añadir un nodo al final de la lista
void agregarAlFinal(Nodo** cabeza, int valor) {   // Toma un puntero a la cabeza de la lista y un valor entero para añadir al final.
    Nodo* nuevoNodo = crearNodo(valor);           // Crea un nuevo nodo con el valor proporcionado.
    if (*cabeza == NULL) {                        // Si la lista está vacía (cabeza es NULL),
        *cabeza = nuevoNodo;                      // el nuevo nodo se convierte en la cabeza.
    } else {                                      // De lo contrario,
        Nodo* actual = *cabeza;                   // comienza desde la cabeza de la lista.
        while (actual->siguiente != NULL) {       // Recorre la lista hasta encontrar el último nodo.
            actual = actual->siguiente;           // Avanza al siguiente nodo.
        }
        actual->siguiente = nuevoNodo;            // El último nodo ahora apunta al nuevo nodo.
    }
}

// Función para añadir un nodo entre otros nodos (ordenado)
void agregarEntreNodos(Nodo** cabeza, int valor) {   // Toma un puntero a la cabeza de la lista y un valor entero para añadir de forma ordenada.
    Nodo* nuevoNodo = crearNodo(valor);              // Crea un nuevo nodo con el valor proporcionado.
    if (*cabeza == NULL || (*cabeza)->dato >= valor) {  // Si la lista está vacía o el valor es menor que el dato en la cabeza,
        agregarAlPrincipio(cabeza, valor);              // el nuevo nodo se añade al principio.
    } else {                                            // De lo contrario,
        Nodo* actual = *cabeza;                         // comienza desde la cabeza.
        while (actual->siguiente != NULL && actual->siguiente->dato < valor) {  // Encuentra la posición correcta donde el valor debe insertarse.
            actual = actual->siguiente;                                         // Avanza al siguiente nodo.
        }
        nuevoNodo->siguiente = actual->siguiente;  // El nuevo nodo apunta al siguiente nodo en la lista.
        actual->siguiente = nuevoNodo;             // El nodo actual ahora apunta al nuevo nodo.
    }
}

// Función para sumar los nodos en posiciones impares
int sumarImpares(Nodo* cabeza) {               // Toma un puntero a la cabeza de la lista.
    int suma = 0;                              // Inicializa la suma de valores en posiciones impares.
    int posicion = 1;                          // Inicializa la posición del nodo actual en 1.
    Nodo* actual = cabeza;                     // Comienza desde la cabeza de la lista.
    while (actual != NULL) {                   // Mientras haya nodos en la lista,
        if (posicion % 2 != 0) {               // si la posición es impar,
            suma += actual->dato;              // añade el valor del nodo a la suma.
        }
        actual = actual->siguiente;            // Avanza al siguiente nodo.
        posicion++;                            // Incrementa la posición.
    }
    return suma;                               // Devuelve la suma de los valores en posiciones impares.
}

// Función para sumar los nodos en posiciones pares
int sumarPares(Nodo* cabeza) {                // Toma un puntero a la cabeza de la lista.
    int suma = 0;                             // Inicializa la suma de valores en posiciones pares.
    int posicion = 1;                         // Inicializa la posición del nodo actual en 1.
    Nodo* actual = cabeza;                    // Comienza desde la cabeza de la lista.
    while (actual != NULL) {                  // Mientras haya nodos en la lista,
        if (posicion % 2 == 0) {              // si la posición es par,
            suma += actual->dato;             // añade el valor del nodo a la suma.
        }
        actual = actual->siguiente;           // Avanza al siguiente nodo.
        posicion++;                           // Incrementa la posición.
    }
    return suma;                              // Devuelve la suma de los valores en posiciones pares.
}

// Función para verificar las posiciones y valores
void verificarPosiciones(Nodo* cabeza) {       // Toma un puntero a la cabeza de la lista.
    int posicion = 1;                          // Inicializa la posición del nodo actual en 1.
    Nodo* actual = cabeza;                     // Comienza desde la cabeza de la lista.
    while (actual != NULL) {                   // Mientras haya nodos en la lista,
        printf("Posicion %d: %d\n", posicion, actual->dato);  // Imprime la posición y el valor del nodo.
        actual = actual->siguiente;            // Avanza al siguiente nodo.
        posicion++;                            // Incrementa la posición.
    }
}

// Función para borrar nodos en posiciones pares
void borrarPares(Nodo** cabeza) {              // Toma un puntero a la cabeza de la lista.
    if (*cabeza == NULL) return;               // Si la lista está vacía, no hace nada.
    Nodo* actual = *cabeza;                    // Comienza desde la cabeza de la lista.
    Nodo* anterior = NULL;                     // Inicializa el puntero 'anterior' como NULL.
    int posicion = 1;                          // Inicializa la posición del nodo actual en 1.
    while (actual != NULL) {                   // Mientras haya nodos en la lista,
        if (posicion % 2 == 0) {               // si la posición es par,
            Nodo* temp = actual;               // Guarda el nodo actual en un temporal.
            if (anterior != NULL) {            // Si no es el primer nodo,
                anterior->siguiente = actual->siguiente;  // omite el nodo actual.
            }
            actual = actual->siguiente;        // Avanza al siguiente nodo.
            free(temp);                        // Libera la memoria del nodo eliminado.
        } else {                               // Si la posición no es par,
            anterior = actual;                 // actualiza 'anterior' al nodo actual.
            actual = actual->siguiente;        // Avanza al siguiente nodo.
        }
        posicion++;                            // Incrementa la posición.
    }
}

// Función para borrar nodos en posiciones impares
void borrarImpares(Nodo** cabeza) {            // Toma un puntero a la cabeza de la lista.
    if (*cabeza == NULL) return;               // Si la lista está vacía, no hace nada.
    Nodo* actual = *cabeza;                    // Comienza desde la cabeza de la lista.
    Nodo* anterior = NULL;                     // Inicializa el puntero 'anterior' como NULL.
    int posicion = 1;                          // Inicializa la posición del nodo actual en 1.
    while (actual != NULL) {                   // Mientras haya nodos en la lista,
        if (posicion % 2 != 0) {               // si la posición es impar,
            Nodo* temp = actual;               // Guarda el nodo actual en un temporal.
            if (anterior != NULL) {            // Si no es el primer nodo,
                anterior->siguiente = actual->siguiente;  // omite el nodo actual.
            } else {                           // Si es el primer nodo,
                *cabeza = actual->siguiente;   // actualiza la cabeza.
            }
            actual = actual->siguiente;        // Avanza al siguiente nodo.
            free(temp);                        // Libera la memoria del nodo eliminado.
        } else {                               // Si la posición no es impar,
            anterior