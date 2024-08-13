#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include <iostream>

//número cuenta
// tipo transacción
// monto
// fecha y hora

// Declaración de la clase Persona
class Transaccion {
private:
    int cuenta;
    int monto;
    std::string tipo_transaccion;
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;

public:
    // Constructor que inicializa los atributos nombre, edad y fecha
    Transaccion(int cuenta,int monto, std::string tipo_transaccion, int anio, int mes, int dia, int hora, int minuto);

    // Métodos para obtener los valores de los atributos
    int getCuenta() const;
    int getMonto() const;
    std::string getTipo_transaccion() const;
    std::string getFecha() const;
    std::string getHora() const;

    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, const Transaccion& transaccion);

    // Sobrecarga de los operadores de comparación
    bool operator>(const Transaccion& otra) const;
    bool operator<(const Transaccion& otra) const;
    bool operator==(const Transaccion& otra) const;
    
};

#endif // 
