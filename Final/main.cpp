#include <iostream>
#include <vector>
#include <chrono> // Biblioteca para medir el tiempo de ejecución
#include "objeto.h"
#include "archivo.h"
#include "listaligada.h"
#include <variant>

void listas(){
        ListaLigada lista;
        for (int i = 0; i < 20; i++) {
    lista.agregar(Objeto("medico"));
    }
    lista.imprimir();

std::cout<<"==========================================="<<std::endl;
    ListaLigada lista2;
        for (int i = 0; i < 20; i++) {
    lista2.agregar(Objeto("medico"));
    }
    lista2.imprimir();
std::cout<<"==========================================="<<std::endl;
    ListaLigada lista3;
        for (int i = 0; i < 20; i++) {
    lista3.agregar(Objeto("medico"));
    }
    lista3.imprimir();

std::cout<<"==========================================="<<std::endl;
    ListaLigada lista4;
        for (int i = 0; i < 20; i++) {
    lista4.agregar(Objeto("medico"));
    }
    lista4.imprimir();
}


std::variant<int,std::string> metodo(int a){
    if (a==1) return 1;
    else return "hola";

}


int main() {
        ListaLigada lista;
        for (int i = 0; i < 2000; i++) {
            
    lista.agregar(Objeto("vuelo"));
    }
    lista.imprimir();
std::cout<<"==========================================="<<std::endl;
    lista.ordenarBurbuja("vuelo","hora",1);
    lista.imprimir();



}


