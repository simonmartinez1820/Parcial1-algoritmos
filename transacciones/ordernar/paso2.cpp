#include <iostream>
#include <chrono> // Biblioteca para medir el tiempo de ejecución
#include "archivo.h"
#include "transaccion.h"
#include "listaligada.h"

Archivo generador;
Archivo generador2;

void cargarDatos(ListaLigada &lista) {
    // Cargar datos en el archivo generador y generador2
    generador.leerDesdeArchivo("transferencias.txt");

   
  
    for (int i = 0; i < 40; i++) {
        // Agregar personas con nombres aleatorios, edades y fechas aleatorias a la lista
        lista.agregar(Transaccion(
        generador.generarNumeroEntero(111111,999999),
        generador.generarNumeroEntero(10000,1000000),
        generador.obtenerItemAleatorio(),
        generador.generarNumeroEntero(1970,2023),
        generador.generarNumeroEntero(1,12),
        generador.generarNumeroEntero(1,28),
        generador.generarNumeroEntero(0,24),
        generador.generarNumeroEntero(0,60)
        ));
    }
}

template <typename Func>
void medirTiempoOrdenamiento(Func funcionOrdenamiento, ListaLigada &lista, const std::string &nombreMetodo) {
    // Medir el tiempo que tarda el método de ordenamiento en ordenar la lista
    auto inicio = std::chrono::high_resolution_clock::now();
    
    funcionOrdenamiento();
    
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    
    std::cout << "Tiempo de " << nombreMetodo << ": " << duracion.count() << " segundos" << std::endl;
}

int main() {
    // Crear una lista ligada y cargar datos
    ListaLigada lista;

    cargarDatos(lista);
    
    std::cout << "Lista original:" << std::endl;
    // lista.imprimir();
    
    // Clonar la lista para las pruebas de ordenamiento
    ListaLigada listaBurbuja = lista;
    ListaLigada listaMergeSort = lista;
    ListaLigada listaQuickSort = lista;
    
    // Medir tiempo para Burbuja
    // medirTiempoOrdenamiento([&]() { listaBurbuja.ordenarBurbuja(); }, listaBurbuja, "ordenarBurbuja");
    // std::cout << "Lista ordenada por Burbuja:" << std::endl;
    // listaBurbuja.imprimir();
    
    // Medir tiempo para MergeSort
    medirTiempoOrdenamiento([&]() { listaMergeSort.mergeSort(); }, listaMergeSort, "mergeSort");
    std::cout << "Lista ordenada por MergeSort:" << std::endl;
    listaMergeSort.imprimir();
    
    // Medir tiempo para QuickSort
    medirTiempoOrdenamiento([&]() { listaQuickSort.quickSort(); }, listaQuickSort, "quickSort");
    std::cout << "Lista ordenada por QuickSort:" << std::endl;
    // listaQuickSort.imprimir();
    
    return 0;
}
