# Variables
CXX = g++
CXXFLAGS = -Wall  #opción -Wall es una bandera del compilador g++ que habilita una serie de advertencias (warnings) útiles
OBJ = paso2.o transaccion.o nodo.o listaligada.o archivo.o
TARGET = programa

# Regla para compilar el programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar paso2.cpp
paso2.o: paso2.cpp transaccion.h nodo.h listaligada.h archivo.h
	$(CXX) $(CXXFLAGS) -c paso2.cpp

# Regla para compilar transaccion.cpp
transaccion.o: transaccion.cpp transaccion.h
	$(CXX) $(CXXFLAGS) -c transaccion.cpp

# Regla para compilar nodo.cpp
nodo.o: nodo.cpp nodo.h transaccion.h
	$(CXX) $(CXXFLAGS) -c nodo.cpp

# Regla para compilar listaligada.cpp
listaligada.o: listaligada.cpp listaligada.h nodo.h transaccion.h
	$(CXX) $(CXXFLAGS) -c listaligada.cpp

# Regla para compilar archivo.cpp
archivo.o: archivo.cpp archivo.h
	$(CXX) $(CXXFLAGS) -c archivo.cpp

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
