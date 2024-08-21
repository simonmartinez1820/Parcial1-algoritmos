
#include <string>
#include <tuple>
#include <vector>
#include <variant>
#include <any>
#include "archivo.h"
#include "objeto.h"
#include <unordered_map>
#include <functional>

//número cuenta
// tipo transacción
// monto
// fecha y hora

using namespace std;


// Constructor que inicializa los atributos

Objeto::Objeto( const std::string a){

    std::unordered_map<std::string, void(Objeto::*)()> funciones;

    funciones["medico"] = &Objeto::cargarMedico;
    funciones["transaccion"] = &Objeto::cargarTransferencia;
    funciones["vuelos"] = &Objeto::cargarVuelos;
    funciones["peliculas"] = &Objeto::cargarPeliculas;
    funciones["electronicos"] = &Objeto::cargarElectronicos;
    funciones["empleados"] = &Objeto::cargarEmpleados;
    funciones["stock"] = &Objeto::cargarStock;
    funciones["estudiante"] = &Objeto::cargarEstudiantes;
    funciones["biblioteca"] = &Objeto::cargarBiblioteca;
    funciones["venta"] = &Objeto::cargarVentas;


    (this->*funciones[a])();
    
}

Archivo generador;

void Objeto::cargarMedico(){
    hashmap.clear();
    generador.limpiar();
 
    generador.leerDesdeArchivo("datos/nombre.txt");
    generador.leerDesdeArchivo2("datos/apellido.txt");
    generador.leerDesdeArchivo3("datos/diagnostico.txt");

   
    int id = generador.generarNumeroEntero(11111,99999);
    std::string nombre =  generador.obtenerItemAleatorio();
    std::string fecha1 = generador.fechaAleatoria(1950,2020);
    std::string diagnostico = generador.obtenerItemAleatorio3();
    std::string fecha2 = generador.fechaAleatoria(1950,2020);
    criterio1 = id;
    
    if(fecha1<fecha2){
        std:string temporal = fecha1;
        fecha1 = fecha2;
        fecha2 = fecha1;
    }
    criterio2 = fecha1;
    
        hashmap.insert({"fecha_salida", fecha1});
        hashmap.insert({"diagnostico", diagnostico});
        hashmap.insert({"fecha_entrada", fecha2});
        hashmap.insert( {"nombre", nombre});
        hashmap.insert({"id", std::to_string(id)});


}

void Objeto::cargarTransferencia(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/transaccion.txt");

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
    generador.leerDesdeArchivo("datos/ciudades.txt");

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

void Objeto::cargarPeliculas(){

    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/nombre.txt");
    generador.leerDesdeArchivo2("datos/apellido.txt");
    generador.leerDesdeArchivo3("datos/peliculas.txt");

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
    generador.leerDesdeArchivo("datos/electrodomesticos.txt");
    generador.leerDesdeArchivo2("datos/marcas.txt");

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

void Objeto::cargarEmpleados(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/nombre.txt");
    generador.leerDesdeArchivo2("datos/apellido.txt");
    generador.leerDesdeArchivo3("datos/departamento.txt");

    std::string nombre = generador.obtenerItemAleatorio()+" "+generador.obtenerItemAleatorio2();
    int id =  generador.generarNumeroEntero(111111,999999);
    std::string departamento = generador.obtenerItemAleatorio3();
    int salario =  generador.generarNumeroEntero(100,500);
    std::string fecha = generador.fechaAleatoria(1950,2020);

    criterio1 = salario;
    criterio2 = fecha;

        hashmap.insert({"nombre",nombre });
        hashmap.insert( {"id", std::to_string(id)});
        hashmap.insert({"departamento", departamento});
        hashmap.insert( {"salario", std::to_string(salario)+" dolares"});
        hashmap.insert({"nombre", nombre});

}

void Objeto::cargarStock(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/electrodomesticos.txt");


    int codigo =  generador.generarNumeroEntero(111111,999999);
    std::string producto = generador.obtenerItemAleatorio();
    int cantidad =  generador.generarNumeroEntero(0,500);
    int precio =  generador.generarNumeroEntero(120000,1000000);
    std::string fecha = generador.fechaAleatoria(1950,2020);

    criterio1 = codigo;
    criterio2 = std::to_string(cantidad);

        hashmap.insert({"fecha",fecha });
        hashmap.insert( {"precio", std::to_string(precio)});
        hashmap.insert( {"cantidad", std::to_string(cantidad)});
        hashmap.insert({"producto",producto });
        hashmap.insert( {"codigo", std::to_string(codigo)});
        
}

void Objeto::cargarEstudiantes(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/nombre.txt");
    generador.leerDesdeArchivo2("datos/apellido.txt");

    std::string nombre = generador.obtenerItemAleatorio()+" "+generador.obtenerItemAleatorio2();
    int id =  generador.generarNumeroEntero(111111,999999);
    float promedio =  generador.generarNumeroFloat(0,5);
    std::string fecha = generador.fechaAleatoria(1950,2020);
    
    criterio1 = id;
    criterio2 = std::to_string(promedio);

        hashmap.insert({"fecha nacimiento",fecha });
        hashmap.insert( {"promedio", std::to_string(promedio)});
        hashmap.insert( {"id", std::to_string(id)});
        hashmap.insert({"nombre",nombre });

        
}

void Objeto::cargarBiblioteca(){
    hashmap.clear();
    generador.limpiar();
    generador.leerDesdeArchivo("datos/nombre.txt");
    generador.leerDesdeArchivo2("datos/apellido.txt");
    generador.leerDesdeArchivo3("datos/titulos.txt");
// Crear registros de libros con título, autor, ISBN, año de publicación y número de copias disponibles.
    std::string titulo = generador.obtenerItemAleatorio3();
    int ISBN =  generador.generarNumeroEntero(111111,999999);
    std::string autor = generador.obtenerItemAleatorio()+" "+generador.obtenerItemAleatorio2();
    int año = generador.generarNumeroEntero(1900,2000);
    int copias =  generador.generarNumeroEntero(0,5000);
    
    criterio1 = año;
    criterio2 = std::to_string(ISBN);

        hashmap.insert( {"copias", std::to_string(copias)});
        hashmap.insert({"año",std::to_string(año) });
        hashmap.insert( {"autor", autor});
        hashmap.insert( {"ISBN", std::to_string(ISBN)});
        hashmap.insert({"titulo",titulo });

        
}

void Objeto::cargarVentas(){
    hashmap.clear();
    generador.limpiar();
   
// Generar datos de ventas que incluyan ID de producto, cantidad vendida, precio unitario y fecha de venta.
    int id =  generador.generarNumeroEntero(111111,999999);
    int cantidad =  generador.generarNumeroEntero(0,5000);
    int precio =  generador.generarNumeroEntero(0,5000);
    std::string fecha = generador.fechaAleatoria(1900,2000);

    criterio1 = precio;
    criterio2 = fecha;

        hashmap.insert({"fecha",fecha });
        hashmap.insert( {"precio", std::to_string(precio)});
        hashmap.insert( {"cantidad", std::to_string(cantidad)});
        hashmap.insert( {"id producto", std::to_string(id)});

        
}



bool Objeto::comparacion(const Objeto& otra,int criterio) const{
    
    // if (criterio == 1) return getCriterio1()>otra.getCriterio1();
    // else if (criterio == 2) return (getHashmap()[str2]<otra.getHashmap()[str2]);
    // else if (criterio == 3) return (getHashmap()[str1]+getHashmap()[str2]<otra.getHashmap()[str1]+otra.getHashmap()[str2]);
    // else if (criterio == 4) return (getHashmap()[str2]+getHashmap()[str1]<otra.getHashmap()[str2]+otra.getHashmap()[str1]);
    // else return false;

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



bool Objeto::operator<(const Objeto& otra) const {
    return getCriterio1() < otra.getCriterio1();
}
bool Objeto::operator>(const Objeto& otra) const {
    return getCriterio1() > otra.getCriterio1();
}
bool Objeto::operator<=(const Objeto& otra) const {
    return getCriterio2() < otra.getCriterio2();
}
bool Objeto::operator>=(const Objeto& otra) const {
    return getCriterio2() > otra.getCriterio2();
}


bool Objeto::operator==(const Objeto& otra) const {
    return getCriterio1() == otra.getCriterio1();
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