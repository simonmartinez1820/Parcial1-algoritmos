#ifndef NODO_H
#define NODO_H

#include "Objeto.h"

// Declaración de la clase Nodo
class Nodo {
public:
    Objeto data;       // Atributo para almacenar los datos del nodo, en este caso una instancia de Persona
    Nodo* siguiente;    // Puntero al siguiente nodo en la lista ligada

    // Constructor que inicializa el atributo data y establece el puntero siguiente a nullptr
    Nodo(const Objeto& data);
};

#endif // NODO_H
