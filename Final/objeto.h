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


        std::unordered_map<std::string, std::string> hashmap;
        int criterio1;
        std::string criterio2;
    

public:

    // Constructor que inicializa los atributos nombre, edad y fecha
    Objeto(const std::string);
    
    std::unordered_map<std::string, std::string> getHashmap() const;
    int getCriterio1() const;
    std::string getCriterio2() const;
    bool comparacion(const Objeto& otra,int) const;
    void cargarMedico();
    void cargarPeliculas();
    void cargarEmpleados();
    void cargarVuelos();
    void cargarElectronicos();
    void cargarTransferencia();
    void cargarStock();
    void cargarEstudiantes();
    void cargarBiblioteca();
    void cargarVentas();

    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, Objeto& otra);
    bool operator<(const Objeto& otra) const;
    bool operator>(const Objeto& otra) const;
    bool operator<=(const Objeto& otra) const;
    bool operator>=(const Objeto& otra) const;
    bool operator==(const Objeto& otra) const;
    
};

#endif // 
