# Variables
CXX = g++
CXXFLAGS = -Wall  #opción -Wall es una bandera del compilador g++ que habilita una serie de advertencias (warnings) útiles
OBJ = paso1.o producto.o nodo.o listaligada.o archivo.o
TARGET = programa

# Regla para compilar el programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar paso1.cpp
paso1.o: paso1.cpp producto.h nodo.h listaligada.h archivo.h
	$(CXX) $(CXXFLAGS) -c paso1.cpp

# Regla para compilar producto.cpp producto.o: producto.cpp producto.h
producto.o: producto.cpp producto.h
	$(CXX) $(CXXFLAGS) -c producto.cpp

# Regla para compilar nodo.cpp
nodo.o: nodo.cpp nodo.h producto.h
	$(CXX) $(CXXFLAGS) -c nodo.cpp

# Regla para compilar listaligada.cpp
listaligada.o: listaligada.cpp listaligada.h nodo.h producto.h
	$(CXX) $(CXXFLAGS) -c listaligada.cpp

# Regla para compilar archivo.cpp
archivo.o: archivo.cpp archivo.h
	$(CXX) $(CXXFLAGS) -c archivo.cpp

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
