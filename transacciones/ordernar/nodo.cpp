#include "nodo.h"

// Implementación del constructor de la clase Nodo
Nodo::Nodo(const Transaccion& data) : data(data), siguiente(nullptr) {}
