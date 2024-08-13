#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
// #include "archivo.h"
#include "transaccion.h"
#include "listaligada.h"
#include "Archivo.h"


using namespace std;

int main() {
    Archivo generador;

    ListaLigada lista;

    int i = 250;
 
    generador.leerDesdeArchivo("transferencias.txt");
    while(i--){
        
        std::string tipo = generador.obtenerItemAleatorio();
        int anio = generador.generarNumeroEntero(1970,2023);
        int mes = generador.generarNumeroEntero(1,12);
        int dia = generador.generarNumeroEntero(1,28);
        int hora = generador.generarNumeroEntero(0,24);
        int minuto = generador.generarNumeroEntero(0,60);
        int cuenta = generador.generarNumeroEntero(111111,999999);
        int valor = generador.generarNumeroEntero(10000,1000000);
        
        lista.agregar(Transaccion (cuenta, valor,tipo,anio,mes,dia,hora,minuto));
    }
    lista.imprimir();
    std::cout<<"====="<<endl;
    lista.ordenarBurbuja();
    lista.imprimir();
    
    return 0;
}
// g++ paso1.cpp transaccion.cpp nodo.cpp listaligada.cpp archivo.cpp 
// g++ -o programa paso1.o transaccion.o nodo.o listaligada.o archivo.o