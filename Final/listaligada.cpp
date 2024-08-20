#include "listaligada.h"
#include <iostream>
#include <variant>
#include <chrono> // Biblioteca para medir el tiempo de ejecución



// Constructor que inicializa la lista vacía
ListaLigada::ListaLigada() : cabeza(nullptr) {}

// Destructor que libera la memoria de todos los nodos
ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}
// Método para agregar un nodo al final de la lista
void ListaLigada::agregar(const Objeto& objeto) {
    Nodo* nuevoNodo = new Nodo(objeto); // Crear un nuevo nodo con los datos de objeto
    if (cabeza == nullptr) {
        cabeza = nuevoNodo; // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente; // Avanzar hasta el último nodo
        }
        actual->siguiente = nuevoNodo; // Añadir el nuevo nodo al final
    }
}

// Método para imprimir todos los nodos de la lista
void ListaLigada::imprimir() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->data << std::endl; // Imprimir los datos del nodo actual
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}


// Método para intercambiar dos nodos si el left es mayor que el right
void ListaLigada::intercambiar(Nodo* nodo1, Nodo* nodo2) {
    Objeto temp = nodo1->data; // Guardar temporalmente los datos de nodo1
    nodo1->data = nodo2->data; // Copiar los datos de nodo2 a nodo1
    nodo2->data = temp; // Copiar los datos originales de nodo1 a nodo2
}

// Método para ordenar la lista usando el método de burbuja



void ListaLigada::ordenarBurbuja() {
    if (cabeza == nullptr) return; // Si la lista está vacía, no hacer nada

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            bool temp = actual->data>actual->siguiente->data;

            if (temp) {
                intercambiar(actual, actual->siguiente); // Intercambiar nodos si están en el orden incorrecto
                intercambiado = true;
            }
            actual = actual->siguiente; // Avanzar al siguiente nodo
        }
    } while (intercambiado); // Repetir hasta que no haya intercambios
}





// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo* ListaLigada::dividir(Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto) {
    if (bajo == nullptr || alto == nullptr) return nullptr; // Verificar si la lista es válida

    Nodo* pivote = alto; // El último nodo es el pivote
    Nodo* previo = nullptr;
    Nodo* actual = bajo;
    Nodo* cola = pivote;

    while (actual != pivote) {
        // actual->data < pivote->data
        if (actual->data > pivote->data) {
            if (*nuevoBajo == nullptr) *nuevoBajo = actual;
            previo = actual;
            actual = actual->siguiente; // Avanzar al siguiente nodo
        } else {
            if (previo) previo->siguiente = actual->siguiente;
            Nodo* temp = actual->siguiente;
            actual->siguiente = nullptr;
            cola->siguiente = actual;
            cola = actual;
            actual = temp;
        }
    }

    if (*nuevoBajo == nullptr) *nuevoBajo = pivote;
    *nuevoAlto = cola;

    return pivote;
}

// Método auxiliar para realizar el QuickSort de manera recursiva
void ListaLigada::quickSortRec(Nodo* bajo, Nodo* alto) {
    if (bajo != nullptr && alto != nullptr && bajo != alto && bajo != alto->siguiente) {
        Nodo* nuevoBajo = nullptr;
        Nodo* nuevoAlto = nullptr;

        Nodo* pivote = dividir(bajo, alto, &nuevoBajo, &nuevoAlto);

        if (nuevoBajo != pivote) {
            Nodo* temp = nuevoBajo;
            while (temp->siguiente != pivote) temp = temp->siguiente;
            temp->siguiente = nullptr;

            quickSortRec(nuevoBajo, temp);

            temp = obtenerUltimo(nuevoBajo);
            temp->siguiente = pivote;
        }

        quickSortRec(pivote->siguiente, nuevoAlto);
    }
}

// Método auxiliar para obtener el último nodo de una lista
Nodo* ListaLigada::obtenerUltimo(Nodo* cabeza) {
    while (cabeza != nullptr && cabeza->siguiente != nullptr) {
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }
    return cabeza; // Retornar el último nodo
}

// Método para ordenar la lista usando el método de QuickSort
void ListaLigada::quickSort() {
    Nodo* cola = obtenerUltimo(cabeza);
    quickSortRec(cabeza, cola);
}





// Método auxiliar para dividir la lista en dos mitades
Nodo* ListaLigada::split(Nodo* head) {
    if (head == nullptr || head->siguiente == nullptr) {
        return nullptr; // La lista está vacía o tiene un solo nodo
    }

    Nodo* slow = head;
    Nodo* fast = head;
    while (fast->siguiente != nullptr && fast->siguiente->siguiente != nullptr) {
        slow = slow->siguiente; // Avanzar el puntero lento
        fast = fast->siguiente->siguiente; // Avanzar el puntero rápido
    }

    Nodo* mitad = slow->siguiente; // La segunda mitad comienza en el siguiente nodo del puntero lento
    slow->siguiente = nullptr; // Dividir la lista en dos mitades
    return mitad;
}

// Método auxiliar para fusionar dos listas ordenadas
Nodo* ListaLigada::merge(Nodo* left, Nodo* right, int criterio) {
    if (left == nullptr) return right; // Si la lista izquierda está vacía, devolver la lista derecha
    if (right == nullptr) return left; // Si la lista derecha está vacía, devolver la lista izquierda
// left->data>right->data
bool temp ;
if (criterio == 0) temp = left->data<right->data;
if (criterio == 1) temp = left->data>right->data;
            if (temp) {
        left->siguiente = merge(left->siguiente, right,criterio); // Fusionar el resto de la lista izquierda con la lista derecha
        return left;
    } else {
        right->siguiente = merge(left, right->siguiente,criterio); // Fusionar la lista izquierda con el resto de la lista derecha
        return right;
    }
}

// Método auxiliar para realizar el Merge Sort de manera recursiva
Nodo* ListaLigada::mergeSortRec(Nodo* head, int criterio) {
    if (head == nullptr || head->siguiente == nullptr) {
        return head; // Si la lista está vacía o tiene un solo nodo, ya está ordenada
    }

    Nodo* mitad = split(head); // Dividir la lista en dos mitades
    Nodo* izquierda = mergeSortRec(head,criterio); // Ordenar la primera mitad
    Nodo* derecha = mergeSortRec(mitad,criterio); // Ordenar la segunda mitad

    return merge(izquierda, derecha,criterio); // Fusionar las dos mitades ordenadas
}

// Método para ordenar la lista usando el método de Merge Sort
void ListaLigada::mergeSort(int criterio) {
    cabeza = mergeSortRec(cabeza, criterio); // Ordenar la lista y actualizar la cabeza
}