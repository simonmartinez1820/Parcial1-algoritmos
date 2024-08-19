#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include <iostream>
#include <variant>
#include <tuple>
#include <any>
#include <vector>
#include <unordered_map>

//número cuenta
// tipo transacción
// monto
// fecha y hora

using variable = std::variant<int, std::string>;

// Declaración de la clase Persona
class Objeto {
private:

        std::vector<std::string> atributos;
        std::vector<std::string> valores;
                std::unordered_map<std::string, std::string> hashmap;

        // hacerlos funciones del objeto para llamarlo



    

public:

    // Constructor que inicializa los atributos nombre, edad y fecha
    Objeto( const std::string);
    
    std::unordered_map<std::string, std::string> getHashmap() const;

    bool comparacion(const Objeto& otra,std::string ,std::string ,int);
    void cargarMedico();
    void cargarTransferencia();
    void cargarVuelos();
    void cargarPeliculas();
    void cargarElectronicos();

    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, Objeto& transaccion);
    
};

#endif // 
