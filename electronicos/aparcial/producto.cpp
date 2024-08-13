#include "producto.h"
#include <string>

// nombre str
// marca str
// precio int
// especificaciones tecnicas (watts) int
// fecha lanzamiento int
using namespace std;


// Constructor que inicializa los atributos nombre, edad y fecha

Producto::Producto(std::string nombre,std::string marca, int precio, int anio, int mes, int dia) 
    : nombre(nombre), marca(marca),precio(precio),anio(anio),mes(mes),dia(dia) {}


std::string Producto::getNombre() const {
    return nombre;
}

std::string Producto::getMarca() const {
    return marca;
}

int Producto::getPrecio() {
    return precio;
}

std::string Producto::getFecha() const {
    std::string str1 = std::to_string(anio);
    std::string str2 = std::to_string(mes);
    std::string str3 = std::to_string(dia);
    std::string tiempo = str1+"/"+str2+"/"+str3;
    return tiempo; 

}



// Sobrecarga del operador > para comparar dos objetos Persona por edad
bool Producto::operator>(const Producto& otro) const {
    return precio > otro.precio;
}

// Sobrecarga del operador < para comparar dos objetos Persona por edad
bool Producto::operator<(const Producto& otro) const {
    return precio < otro.precio;
}

// Sobrecarga del operador == para comparar dos objetos Persona por edad
bool Producto::operator==(const Producto& otro) const {
    return precio == otro.precio;
}

std::ostream& operator<<(std::ostream& os, const Producto& Producto) {
    // int nombre,int marca, std::string precio, int anio, int mes, int dia, int hora, int minuto
    os << "nombre: " << Producto.nombre <<", precio: "<<Producto.precio<< ", marca: " << Producto.marca <<", fecha: "<<Producto.getFecha();
    return os;
}