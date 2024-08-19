#ifndef ARCHIVOH
#define ARCHIVO_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>  // Para std::rand y std::srand
#include <ctime>    // Para std::time
#include <iomanip>  // Para std::setw y std::setfill

class Archivo {
private:
    std::vector<std::string> items;
    std::vector<std::string> items2;
    std::vector<std::string> items3;

public:
    // Constructor
Archivo();
    // Método para leer los items desde un archivo
    void leerDesdeArchivo(const std::string& nombreArchivo);
    void leerDesdeArchivo2(const std::string& nombreArchivo);
    void leerDesdeArchivo3(const std::string& nombreArchivo);

    // Método para imprimir los items
    void imprimirItems();

    // Método para retornar un item aleatorio
    std::string obtenerItemAleatorio();
    std::string obtenerItemAleatorio2();
    std::string obtenerItemAleatorio3();

    // Método para generar una fecha aleatoria en formato dia/mes/año
    std::string fechaAleatoria(int añoInicial, int fechaTope) const;

    // Método para generar una hora aleatoria en formato 24h
    std::string horaAleatoria() const;

    // Método para generar un número entero aleatorio en un rango
    int generarNumeroEntero(int min, int max) const;

    // Método para generar un número flotante aleatorio en un rango
    float generarNumeroFloat(float min, float max) const;
    void limpiar();
};

#endif // ARCHIVO_H
