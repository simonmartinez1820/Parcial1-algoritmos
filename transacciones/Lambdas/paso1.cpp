#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "archivo.h"
#include "transaccion.h"


// Archivo generador;
// Archivo generador2;

// void cargarDatos(Archivo &gener, const std::string& file) {
//     gener.leerDesdeArchivo(file);
// }

// std::string SimularNombreCompleto() {
//     std::string nombreCompleto = generador.obtenerItemAleatorio() + " " +
//                                  generador2.obtenerItemAleatorio() + " " +
//                                  generador2.obtenerItemAleatorio();
//     return nombreCompleto;
// }
using namespace std;

void prin(Transaccion transaccion,int(*func)()){

    std:cout<<transaccion.func();

}

int main() {
    Archivo generador;

    // (int cuenta, int monto, std::string& tipo_transaccion, const std::string& fecha, int hora) 
    
    auto lambda = []()

    int i = 250000;
 
    generador.leerDesdeArchivo("transferencias.txt");
    
        std::string tipo = generador.obtenerItemAleatorio();
        int anio = generador.generarNumeroEntero(1970,2023);
        int mes = generador.generarNumeroEntero(1,12);
        int dia = generador.generarNumeroEntero(1,28);
        int hora = generador.generarNumeroEntero(0,24);
        int minuto = generador.generarNumeroEntero(0,60);
        int cuenta = generador.generarNumeroEntero(111111,999999);
        int valor = generador.generarNumeroEntero(10000,1000000);
        
     Transaccion t (cuenta, valor,tipo,anio,mes,dia,hora,minuto);
     prin(t,Transaccion.getCuenta());
    
    
    // cout<<transaccion<<endl;
    // cargarDatos(generador, "nombres.txt");
    // cargarDatos(generador2, "apellidos.txt");

    // ListaLigada lista;
    // for (int i = 0; i < 1000; i++) {
    //     lista.agregar(Persona(SimularNombreCompleto(), 
    //                           generador.generarNumeroEntero(12, 89),
    //                           generador.fechaAleatoria(1972, 2023)));
    // }
    // ListaLigada lista;
    // lista.agregar(2324234,234234);
    // lista.agregar(678,567);
    // lista.agregar(2324234,34234);
    // lista.agregar(45,86734);
    // std::cout << "Lista antes de ordenar:" << std::endl;
    // lista.imprimir();

    // // Medir el tiempo de ordenación
    // auto inicio = std::chrono::high_resolution_clock::now(); // Captura el tiempo de inicio
    //   //lista.ordenarBurbuja(); // Llama al método de ordenación
    //   lista.mergeSort();
    // auto fin = std::chrono::high_resolution_clock::now(); // Captura el tiempo de fin
    // auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count(); // Calcula la duración en milisegundos

    // std::cout << "Lista después de ordenar:" << std::endl;
    // lista.imprimir();
    // std::cout << "Tiempo de ordenación: " << duracion << " ms" << std::endl; // Imprime la duración
    
    return 0;
}
// g++ paso1.cpp transaccion.cpp nodo.cpp listaligada.cpp archivo.cpp 
// g++ -o programa paso1.o transaccion.o nodo.o listaligada.o archivo.o