class ListaContigua:
    # Constructor para inicializar una lista contigua vacía
    def __init__(self):
        self.lista = []  # Inicializamos la lista como una lista vacía de Python

    # Método para verificar si la lista está vacía
    def es_vacia(self):
        """Verifica si la lista está vacía."""
        return len(self.lista) == 0  # Devuelve True si la longitud de la lista es 0, False en caso contrario

    # Método para obtener el número de elementos en la lista
    def numero_elementos(self):
        """Devuelve el número de elementos en la lista."""
        return len(self.lista)  # Devuelve la longitud de la lista

    # Método para insertar un elemento al final de la lista
    def insertar_al_final(self, elemento):
        """Inserta un elemento al final de la lista."""
        self.lista.append(elemento)  # Utiliza el método append() para agregar el elemento al final
        print(f"Elemento {elemento} agregado al final de la lista.")  # Muestra un mensaje confirmando la inserción

    # Método para borrar un elemento del final de la lista
    def borrar_al_final(self):
        """Borra un elemento del final de la lista."""
        if not self.es_vacia():  # Verifica si la lista no está vacía
            elemento = self.lista.pop()  # Elimina el último elemento usando pop() y lo almacena en 'elemento'
            print(f"Elemento {elemento} eliminado del final de la lista.")  # Muestra un mensaje confirmando la eliminación
        else:
            print("La lista está vacía. No se puede eliminar.")  # Mensaje de advertencia si la lista está vacía

    # Método para mostrar todos los elementos de la lista
    def mostrar_lista(self):
        """Muestra los elementos de la lista."""
        if self.es_vacia():  # Verifica si la lista está vacía
            print("La lista está vacía.")  # Muestra un mensaje si la lista está vacía
        else:
            print("Elementos en la lista:", self.lista)  # Imprime los elementos de la lista


# Función principal para ejecutar la aplicación interactiva
def main():
    # Crear una instancia de ListaContigua
    lista = ListaContigua()  # Se crea una nueva lista contigua

    # Bucle infinito para mostrar el menú hasta que el usuario decida salir
    while True:
        # Mostrar el menú de opciones al usuario
        print("\n--- Menú de Operaciones en Lista Contigua ---")
        print("1. Verificar si la lista está vacía")
        print("2. Mostrar el número de elementos en la lista")
        print("3. Insertar un elemento al final de la lista")
        print("4. Borrar un elemento al final de la lista")
        print("5. Mostrar los elementos de la lista")
        print("6. Salir")

        # Leer la opción seleccionada por el usuario
        opcion = input("Seleccione una opción: ")

        # Verificar si la lista está vacía
        if opcion == "1":
            if lista.es_vacia():  # Llama a es_vacia() para verificar si la lista está vacía
                print("La lista está vacía.")  # Mensaje si la lista está vacía
            else:
                print("La lista no está vacía.")  # Mensaje si la lista no está vacía

        # Mostrar el número de elementos en la lista
        elif opcion == "2":
            print(f"Número de elementos en la lista: {lista.numero_elementos()}")  # Muestra la longitud de la lista

        # Insertar un elemento al final de la lista
        elif opcion == "3":
            try:
                # Solicitar al usuario un número para insertar
                elemento = int(input("Ingrese el elemento a insertar: "))  # Convierte la entrada a entero
                lista.insertar_al_final(elemento)  # Llama a insertar_al_final() para agregar el número
            except ValueError:  # Captura excepciones si el valor ingresado no es un número
                print("Por favor, ingrese un número válido.")  # Mensaje de error para entradas no válidas

        # Borrar un elemento del final de la lista
        elif opcion == "4":
            lista.borrar_al_final()  # Llama a borrar_al_final() para eliminar el último elemento

        # Mostrar todos los elementos de la lista
        elif opcion == "5":
            lista.mostrar_lista()  # Llama a mostrar_lista() para imprimir todos los elementos de la lista

        # Salir del programa
        elif opcion == "6":
            print("Saliendo del programa...")  # Mensaje de salida
            break  # Rompe el bucle infinito para finalizar el programa

        # Manejo de opciones no válidas
        else:
            print("Opción no válida. Por favor, seleccione una opción del 1 al 6.")  # Mensaje de error para opciones inválidas

# Verifica si el script se está ejecutando como programa principal
if __name__ == "__main__":
    main()  # Llama a la función principal main()