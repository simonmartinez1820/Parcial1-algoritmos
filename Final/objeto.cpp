
#include <string>
#include <tuple>
#include <vector>
#include <variant>
#include <any>
#include "archivo.h"
#include "objeto.h"
#include <unordered_map>

//número cuenta
// tipo transacción
// monto
// fecha y hora

using namespace std;


// Constructor que inicializa los atributos

Objeto::Objeto( const std::string a){
   
    if (a == "medico")cargarMedico();
    else if(a =="transaccion") cargarTransferencia();
    else if(a == "vuelo") cargarVuelos();
    else if(a == "pelicula") cargarPeliculas();

    
}
    Archivo generador;


void Objeto::cargarMedico(){
    hashmap.clear();
    generador.limpiar();
 
    generador.leerDesdeArchivo("nombre.txt");
    generador.leerDesdeArchivo2("diagnostico.txt");
   
    int id = generador.generarNumeroEntero(11111,99999);
    std::string nombre =  generador.obtenerItemAleatorio();
    std::string fecha1 = generador.fechaAleatoria(1950,2020);
    std::string diagnostico = generador.obtenerItemAleatorio2();
    std::string fecha2 = generador.fechaAleatoria(1950,2020);
    
        hashmap.insert({"fecha_salida", fecha1});
        hashmap.insert({"diagnostico", diagnostico});
        hashmap.insert({"fecha_entrada", fecha2});
        hashmap.insert( {"nombre", nombre});
        hashmap.insert({"id", std::to_string(id)});


}


void Objeto::cargarTransferencia(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("nombre.txt");

    std::string cuenta = std::to_string(generador.generarNumeroEntero(11111,99999));
    std::string tipo =  generador.obtenerItemAleatorio();
    std::string monto = std::to_string(generador.generarNumeroEntero(1000,20000));
    std::string fecha = generador.fechaAleatoria(1950,2020);
    std::string hora = generador.horaAleatoria();

        hashmap.insert({"hora", hora});
        hashmap.insert({"fecha", fecha});
        hashmap.insert({"monto", monto});
        hashmap.insert( {"tipo", tipo});
        hashmap.insert({"cuenta",cuenta });

}

void Objeto::cargarVuelos(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("ciudades.txt");

    std::string vuelo = std::to_string(generador.generarNumeroEntero(11111,99999));
    std::string origen = generador.obtenerItemAleatorio();
    std::string destino = generador.obtenerItemAleatorio();
    std::string hora = generador.horaAleatoria();
    std::string capacidad  = std::to_string(generador.generarNumeroEntero(100,300));

        hashmap.insert({"capacidad", capacidad});
        hashmap.insert({"hora", hora});
        hashmap.insert({"destino", destino});
        hashmap.insert( {"origen", origen});
        hashmap.insert({"vuelo",vuelo });

}

// volver ambos generadores en uno csolo teniendo varios arrays y que la limpieza sea multiple
void Objeto::cargarPeliculas(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("nombre.txt");
    generador.leerDesdeArchivo2("nombre.txt");

    std::string titulo = generador.obtenerItemAleatorio2();
    std::string director = generador.obtenerItemAleatorio();
    std::string lanzamiento = generador.fechaAleatoria(1950,2020);
    std::string duracion =  std::to_string(generador.generarNumeroEntero(45,130));
    std::string calificacion  = std::to_string(generador.generarNumeroEntero(0,10));
    atributos = {"titulo", "director","lanzamiento","duracion","calificacion"};
    valores = {titulo, director, lanzamiento, duracion, calificacion};

}
void Objeto::cargarElectronicos(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("nombre.txt");
    generador.leerDesdeArchivo2("nombre.txt");

    std::string nombre = generador.obtenerItemAleatorio();
    std::string marca = generador.obtenerItemAleatorio2();
    std::string especificaciones =  std::to_string(generador.generarNumeroEntero(100,500));
    std::string fecha = generador.fechaAleatoria(1950,2020);
    atributos = {"nombre", "marca","especificaciones","fecha"};
    valores = {nombre, marca, especificaciones, fecha};

}


bool isNumber(const std::string& str) {
    // Si la cadena está vacía, no es un número
    if (str.empty()) return false;

    // Verificar si todos los caracteres son dígitos
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}


bool Objeto::comparacion(const Objeto& otra,std::string str1,std::string str2,int criterio){
    
    if (criterio == 1) return (std::stoi(getHashmap()[str1])<std::stoi(otra.getHashmap()[str1]));
    else if (criterio == 2) return (getHashmap()[str2]<otra.getHashmap()[str2]);
    else if (criterio == 3) return (getHashmap()[str1]+getHashmap()[str2]<otra.getHashmap()[str1]+otra.getHashmap()[str2]);
    else if (criterio == 4) return (getHashmap()[str2]+getHashmap()[str1]<otra.getHashmap()[str2]+otra.getHashmap()[str1]);
    else return false;

}

std::unordered_map<std::string, std::string> Objeto::getHashmap() const{
    return hashmap;
}

std::ostream& operator<<(std::ostream& os, Objeto& objeto ) {

    std::string ans;

        for (const auto& pair : objeto.getHashmap()) {
        ans +=  pair.first + ": " + pair.second+" ";
    }

    os << ans;
    ans = "";
    return os;
}