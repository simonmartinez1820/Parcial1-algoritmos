#include "transaccion.h"
#include <string>

//número cuenta
// tipo transacción
// monto
// fecha y hora

using namespace std;


// Constructor que inicializa los atributos nombre, edad y fecha

Transaccion::Transaccion(int cuenta,int monto, std::string tipo_transaccion, int anio, int mes, int dia, int hora, int minuto) 
    : cuenta(cuenta), monto(monto),tipo_transaccion(tipo_transaccion),anio(anio),mes(mes),dia(dia),hora(hora),minuto(minuto) {}


int Transaccion::getCuenta() const {
    return cuenta;
}

int Transaccion::getMonto() const {
    return monto;
}


std::string Transaccion::getTipo_transaccion() const {
    return tipo_transaccion;
}

std::string Transaccion::getFecha() const {
    std::string str1 = std::to_string(anio);
    std::string str2 = std::to_string(mes);
    std::string str3 = std::to_string(dia);
    std::string tiempo = str1+"/"+str2+"/"+str3;
    return tiempo; 

}

std::string Transaccion::getHora() const {
    std::string str1 = std::to_string(hora);
    std::string str2 = std::to_string(minuto);
    if(minuto<10){
    str2 = "0" + str2;
    }
    std::string tiempo = str1+":"+str2;
    return tiempo;
}



// Sobrecarga del operador > para comparar dos objetos Persona por edad
bool Transaccion::operator>(const Transaccion& otra) const {
    return cuenta > otra.cuenta;
}

// Sobrecarga del operador < para comparar dos objetos Persona por edad
bool Transaccion::operator<(const Transaccion& otra) const {
    return cuenta < otra.cuenta;
}

// Sobrecarga del operador == para comparar dos objetos Persona por edad
bool Transaccion::operator==(const Transaccion& otra) const {
    return cuenta == otra.cuenta;
}

std::ostream& operator<<(std::ostream& os, const Transaccion& transaccion) {
    // int cuenta,int monto, std::string tipo_transaccion, int anio, int mes, int dia, int hora, int minuto
    os << "cuenta: " << transaccion.cuenta <<", tipo: "<<transaccion.tipo_transaccion<< ", monto: " << transaccion.monto <<", fecha: "<<transaccion.getFecha()<<
    ", hora: "<< transaccion.getHora();
    return os;
}