#include <iostream>
#include <vector>
#include <chrono> // Biblioteca para medir el tiempo de ejecución
#include "objeto.h"
#include "archivo.h"
#include "listaligada.h"
#include <variant>

ListaLigada lista1,lista2,lista3;

// metodo que crea una lista ligada con la cantidad y criterios indicados
ListaLigada crearLista(int cantidad,std::string objeto){
    ListaLigada lista;
 
        for (int j = 0; j < cantidad; j++) {
            lista.agregar(Objeto(objeto));
        }
        return lista;

}

// generar listas de todos los objetos de la cantidad indicada
void listas(int cantidad){
        
    std::vector<std::string> vector = 
    {"medico", "transaccion", "vuelos", 
    "peliculas", "electronicos", "empleados", 
    "stock", "estudiante", "biblioteca", "venta"};
    for (int i = 0; i < vector.size(); i++) {
    ListaLigada lista;
    std::cout<<"==========================================="<<std::endl;
        for (int j = 0; j < cantidad; j++) {
            lista.agregar(Objeto(vector[i]));
        }
        lista.mergeSort(1);
        lista.imprimir();
        
    }
}


// metodo que aplica los tres metodos de ordenamiento dentro de tres listas difrentes, retornando tiempo
void tiempos(int cantidad, int criterio, std::string objeto){
        for (int i = 0; i < cantidad; i++) {
        lista1.agregar(Objeto(objeto));
    }
    lista2, lista3 = lista1;

    auto inicio = std::chrono::high_resolution_clock::now();
    lista1.ordenarBurbuja(criterio);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de burbuja: " << duracion.count() << " segundos" << std::endl;


    auto inicio2 = std::chrono::high_resolution_clock::now();
    lista2.mergeSort(criterio);
    auto fin2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion2 = fin2 - inicio2;
    std::cout << "Tiempo de merge: " << duracion2.count() << " segundos" << std::endl;



    auto inicio3 = std::chrono::high_resolution_clock::now();
    lista3.quickSort(criterio);
    auto fin3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion3 = fin3 - inicio3;
    std::cout << "Tiempo de quick: " << duracion3.count() << " segundos" << std::endl;
    
}


int main() {

    // "medico", "transaccion", "vuelos", 
    // "peliculas", "electronicos", "empleados", 
    // "stock", "estudiante", "biblioteca", "venta"

    int cantidad = 500;
    int criterio = 1; // 1 es int y 0 str
    tiempos(cantidad,criterio,"transaccion");


    listas(10);

    // crear lista
    ListaLigada lista = crearLista(cantidad,"transaccion");
    lista.imprimir();
    
return 0;

}


