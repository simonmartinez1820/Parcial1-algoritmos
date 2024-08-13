#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

//número cuenta
// tipo transacción
// monto
// fecha y hora

// Declaración de la clase Persona
class Producto {
private:
    std::string nombre;
    std::string marca;
    int precio;
    int anio;
    int mes;
    int dia;

public:
    // Constructor que inicializa los atributos nombre, edad y fecha
    Producto(std::string nombre,std::string marca, int precio, int anio, int mes, int dia);

    // Métodos para obtener los valores de los atributos
    std::string  getNombre() const;
    std::string  getMarca() const;
    int getPrecio() ;
    std::string getFecha() const;


    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, const Producto& Producto);

    // Sobrecarga de los operadores de comparación
    bool operator>(const Producto& otro) const;
    bool operator<(const Producto& otro) const;
    bool operator==(const Producto& otro) const;
    
};

#endif // 
