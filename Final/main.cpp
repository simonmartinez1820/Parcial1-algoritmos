#include <iostream>
#include <vector>
#include <chrono> // Biblioteca para medir el tiempo de ejecución
#include "objeto.h"
#include "archivo.h"
#include "listaligada.h"
#include <variant>



    // if (a == "medico")cargarMedico();
    // else if(a =="transaccion") cargarTransferencia();
    // else if(a == "vuelo") cargarVuelos();
    // else if(a == "pelicula") cargarPeliculas();
    // else if(a == "electronicos") cargarElectronicos();





void listas(int a){
        
    std::vector<std::string> vector = {"medico", "transaccion", "vuelo", "pelicula", "electronicos"};
    for (int i = 0; i < vector.size(); i++) {
    ListaLigada lista;
    std::cout<<"==========================================="<<std::endl;
        for (int j = 0; j < a; j++) {
            lista.agregar(Objeto(vector[i]));
        }
        lista.imprimir();
        
    }
}


int main() {
    ListaLigada lista,lista2,lista3;
    for (int i = 0; i < 20000; i++) {
        lista.agregar(Objeto("medico"));

    }

    auto inicio = std::chrono::high_resolution_clock::now();
    std::cout<<"==========================================="<<std::endl;
    lista.ordenarBurbuja();
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de bubble: " << duracion.count() << " segundos" << std::endl;

    // listas(5);

return 0;

}


