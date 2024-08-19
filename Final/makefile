# Variables
CXX = g++
CXXFLAGS = -Wall  #opción -Wall es una bandera del compilador g++ que habilita una serie de advertencias (warnings) útiles
OBJ = main.o objeto.o nodo.o listaligada.o archivo.o
TARGET = programa

# Regla para compilar el programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar main.cpp
main.o: main.cpp objeto.h nodo.h listaligada.h archivo.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar objeto.cpp
objeto.o: objeto.cpp objeto.h
	$(CXX) $(CXXFLAGS) -c objeto.cpp

# Regla para compilar nodo.cpp
nodo.o: nodo.cpp nodo.h objeto.h
	$(CXX) $(CXXFLAGS) -c nodo.cpp

# Regla para compilar listaligada.cpp
listaligada.o: listaligada.cpp listaligada.h nodo.h objeto.h
	$(CXX) $(CXXFLAGS) -c listaligada.cpp

# Regla para compilar archivo.cpp
archivo.o: archivo.cpp archivo.h
	$(CXX) $(CXXFLAGS) -c archivo.cpp

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
