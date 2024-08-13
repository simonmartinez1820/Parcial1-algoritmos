#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "archivo.h"
#include "producto.h"
#include "listaligada.h"

// #include "Archivo.h"

// Archivo generadorProducto;
// Archivo generador2;

// void cargarDatos(Archivo &gener, const std::string& file) {
//     gener.leerDesdeArchivo(file);
// }

// std::string SimularNombreCompleto() {
//     std::string nombreCompleto = generadorProducto.obtenerItemAleatorio() + " " +
//                                  generador2.obtenerItemAleatorio() + " " +
//                                  generador2.obtenerItemAleatorio();
//     return nombreCompleto;
// }
using namespace std;

int main() {
    ListaLigada lista;
    Producto producto("licuadora","samsung", 22, 1243, 12, 21) ;
    cout<<producto;

    Archivo generadorProducto;
    Archivo generadorMarca;
    

    int i = 200;
 
    generadorProducto.leerDesdeArchivo("producto.txt");
    generadorMarca.leerDesdeArchivo("marcas.txt");
    while(i--){
        
        std::string producto = generadorProducto.obtenerItemAleatorio();
        std::string marca = generadorMarca.obtenerItemAleatorio();
        int valor = generadorProducto.generarNumeroEntero(10000,1000000);
        int anio = generadorProducto.generarNumeroEntero(1970,2023);
        int mes = generadorProducto.generarNumeroEntero(1,12);
        int dia = generadorProducto.generarNumeroEntero(1,28);
        lista.agregar(Producto (producto,marca, valor, anio, mes, dia));
    
    }

    lista.imprimir();
    //     lista.agregar(Transaccion (cuenta, valor,tipo,anio,mes,dia,hora,minuto));
    // }
    // lista.imprimir();
    // std::cout<<"====="<<endl;
    // lista.mergeSort();
    // lista.imprimir();
    return 0;

    // return 0;
}
// g++ paso1.cpp transaccion.cpp nodo.cpp listaligada.cpp archivo.cpp 
// g++ -o programa paso1.o transaccion.o nodo.o listaligada.o archivo.o