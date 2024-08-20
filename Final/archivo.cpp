#include "archivo.h"
#include <iostream>


// Constructor
Archivo::Archivo() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    //std::srand(static_cast<unsigned int>(std::time(0)));
    // Inicializar la semilla para números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Método para leer los textos desde un archivo
void Archivo::leerDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string texto;
        while (std::getline(archivo, texto)) {
            items.push_back(texto);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}
void Archivo::leerDesdeArchivo2(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string texto;
        while (std::getline(archivo, texto)) {
            items2.push_back(texto);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}
void Archivo::leerDesdeArchivo3(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string texto;
        while (std::getline(archivo, texto)) {
            items3.push_back(texto);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}

// Método para imprimir los items
void Archivo::imprimirItems() {
    int i=1;
    for (const auto& item : items) {
        std::cout << "["<< i << "]: " <<item << std::endl;
        i=i+1;
    }
    std::cout << std::endl;
}

// Método para retornar un item aleatorio
std::string Archivo::obtenerItemAleatorio(){
    if (items.empty()) {
        return "No hay nombres en la lista.";
    }
    int indiceAleatorio = std::rand() % items.size();
    return items[indiceAleatorio];
}
std::string Archivo::obtenerItemAleatorio2(){
    if (items.empty()) {
        return "No hay nombres en la lista.";
    }
    int indiceAleatorio = std::rand() % items2.size();
    return items2[indiceAleatorio];
}
std::string Archivo::obtenerItemAleatorio3(){
    if (items.empty()) {
        return "No hay nombres en la lista.";
    }
    int indiceAleatorio = std::rand() % items3.size();
    return items3[indiceAleatorio];
}

// Método para generar una fecha aleatoria en formato dia/mes/año
std::string Archivo::fechaAleatoria(int añoInicial, int fechaTope) const {
    int año = añoInicial + std::rand() % (fechaTope - añoInicial + 1);
    int mes = 1 + std::rand() % 12;
    int dia = 1 + std::rand() % 28;  // Simplificación: todos los meses tienen 28 días

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << año << "/"
       << std::setw(2) << std::setfill('0') << mes << "/"
       << std::setw(2) << std::setfill('0') << dia ;
    return ss.str();
}

// Método para generar un número entero aleatorio en un rango
int Archivo::generarNumeroEntero(int min, int max) const {
    return min + std::rand() % (max - min + 1);
}

// Método para generar un número flotante aleatorio en un rango
float Archivo::generarNumeroFloat(float min, float max) const {
    float random = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    return min + random * (max - min);
}

std::string Archivo::horaAleatoria() const{

    int hora = 1 + std::rand() % 24;
    int minuto = 1 + std::rand() % 60;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hora << ":"
    << std::setw(2) << std::setfill('0') << minuto;
    return ss.str();

}

void Archivo::limpiar(){
items.clear();
items2.clear();
items3.clear();

}

