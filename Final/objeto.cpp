
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
    else if(a == "electronicos") cargarElectronicos();

    
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
    criterio1 = id;
    criterio2 = nombre;
    if(fecha1<fecha2){
        std:string temporal = fecha1;
        fecha1 = fecha2;
        fecha2 = fecha1;
    }
    
        hashmap.insert({"fecha_salida", fecha1});
        hashmap.insert({"diagnostico", diagnostico});
        hashmap.insert({"fecha_entrada", fecha2});
        hashmap.insert( {"nombre", nombre});
        hashmap.insert({"id", std::to_string(id)});


}


void Objeto::cargarTransferencia(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("transaccion.txt");

    int cuenta = generador.generarNumeroEntero(111111,999999);
    std::string tipo =  generador.obtenerItemAleatorio();
    int monto = generador.generarNumeroEntero(1000,2000000);
    std::string fecha = generador.fechaAleatoria(1950,2020);
    std::string hora = generador.horaAleatoria();

    criterio1 = cuenta;
    criterio2 = fecha;

        hashmap.insert({"hora", hora});
        hashmap.insert({"fecha", fecha});
        hashmap.insert({"monto", std::to_string(monto)});
        hashmap.insert( {"tipo", tipo});
        hashmap.insert({"cuenta",std::to_string(cuenta) });

}

void Objeto::cargarVuelos(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("ciudades.txt");

    int vuelo = generador.generarNumeroEntero(11111,99999);
    std::string origen = generador.obtenerItemAleatorio();
    std::string destino = generador.obtenerItemAleatorio();
    std::string hora = generador.horaAleatoria();
    int capacidad  = generador.generarNumeroEntero(100,300);
    criterio1 = vuelo;
    criterio2 = hora;
        hashmap.insert({"capacidad", std::to_string(capacidad)});
        hashmap.insert({"hora", hora});
        hashmap.insert({"destino", destino});
        hashmap.insert( {"origen", origen});
        hashmap.insert({"vuelo",std::to_string(vuelo) });

}

// volver ambos generadores en uno csolo teniendo varios arrays y que la limpieza sea multiple
void Objeto::cargarPeliculas(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("nombre.txt");
    generador.leerDesdeArchivo2("apellido.txt");
    generador.leerDesdeArchivo3("peliculas.txt");

    std::string titulo = generador.obtenerItemAleatorio3();
    std::string director = generador.obtenerItemAleatorio()+" "+generador.obtenerItemAleatorio2();
    int lanzamiento = generador.generarNumeroEntero(1950,2020);
    int duracion =  generador.generarNumeroEntero(45,130);
    int calificacion  = generador.generarNumeroEntero(0,10);
    criterio1 = lanzamiento;
    criterio2 = titulo;

        hashmap.insert({"calificacion", std::to_string(calificacion)});
        hashmap.insert({"duracion", std::to_string(duracion)});
        hashmap.insert({"lanzamiento", std::to_string(lanzamiento)});
        hashmap.insert( {"director", director});
        hashmap.insert({"titulo",titulo });

}
void Objeto::cargarElectronicos(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("electrodomesticos.txt");
    generador.leerDesdeArchivo2("marcas.txt");

    std::string nombre = generador.obtenerItemAleatorio();
    std::string marca = generador.obtenerItemAleatorio2();
    int especificaciones =  generador.generarNumeroEntero(100,500);
    std::string fecha = generador.fechaAleatoria(1950,2020);
    criterio1 = especificaciones;
    criterio2 = fecha;

        hashmap.insert({"fecha",fecha });
        hashmap.insert( {"especificaciones", std::to_string(especificaciones)+"W"});
        hashmap.insert({"marca", marca});
        hashmap.insert({"nombre", nombre});

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


bool Objeto::comparacion(const Objeto& otra,std::string str1,std::string str2,int criterio) const{
    
    if (criterio == 1) return (std::stoi(getHashmap()[str1])<std::stoi(otra.getHashmap()[str1]));
    else if (criterio == 2) return (getHashmap()[str2]<otra.getHashmap()[str2]);
    else if (criterio == 3) return (getHashmap()[str1]+getHashmap()[str2]<otra.getHashmap()[str1]+otra.getHashmap()[str2]);
    else if (criterio == 4) return (getHashmap()[str2]+getHashmap()[str1]<otra.getHashmap()[str2]+otra.getHashmap()[str1]);
    else return false;

}

int Objeto::getCriterio1() const{
    return criterio1;
}
std::string Objeto::getCriterio2() const{
    return criterio2;
}

std::unordered_map<std::string, std::string> Objeto::getHashmap() const{
    return hashmap;
}


// Sobrecarga del operador < para comparar dos objetos Persona por edad
bool Objeto::operator<(const Objeto& otra) const {
    return getCriterio1() < otra.getCriterio1();
}
bool Objeto::operator>(const Objeto& otra) const {
    return getCriterio2() > otra.getCriterio2();
}

// Sobrecarga del operador == para comparar dos objetos Persona por edad
bool Objeto::operator==(const Objeto& otra) const {
    return getCriterio2() == otra.getCriterio2();
}

std::ostream& operator<<(std::ostream& os, Objeto& objeto ) {

    std::string ans;
        for (const auto& items : objeto.getHashmap()) {
        ans +=  items.first + ": " + items.second+" ";
    }

    os << ans;
    ans = "";
    return os;
}