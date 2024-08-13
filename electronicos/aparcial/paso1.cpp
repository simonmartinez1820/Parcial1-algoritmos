#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "archivo.h"
#include "producto.h"
#include "listaligada.h"


using namespace std;

int main() {
    ListaLigada lista;
    Producto producto("licuadora","samsung", 22, 1243, 12, 21) ;
    
    Archivo generadorProducto;
    Archivo generadorMarca;
    

    int i = 20;
 
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
    cout<<"====="<<endl;
    lista.mergeSort();
    lista.imprimir();

    return 0;

    // return 0;
}
// g++ paso1.cpp transaccion.cpp nodo.cpp listaligada.cpp archivo.cpp 
// g++ -o programa paso1.o transaccion.o nodo.o listaligada.o archivo.o