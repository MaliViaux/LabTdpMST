# Makefile para proyecto con clases NodoGrafo, Grafo, HeapFib, NodoHeapFib y tests

# Compilador a usar
CXX = g++
# Opciones de compilación
CXXFLAGS = -Wall -std=c++11 -O3

# .o files for all .cpp files
OBJETOS = NodoGrafo.o Grafo.o HeapFib.o NodoHeapFib.o Prim.o main.o
# .o files for tests
TESTS_OBJETOS = testGrafo.o testNodo.o testPrim.o testHeapFib.o testNodoHeapFib.o

# Targets para los tests
TESTS = testGrafo testNodo testPrim testHeapFib testNodoHeapFib
PROGRAMA = main

# Target por defecto
all: $(PROGRAMA) $(TESTS)

# Regla para el programa principal
main: $(OBJETOS)
	$(CXX) $(CXXFLAGS) -o main $(OBJETOS)

# Regla para enlazar los tests
testGrafo: testGrafo.o Grafo.o NodoGrafo.o
	$(CXX) $(CXXFLAGS) -o testGrafo testGrafo.o Grafo.o NodoGrafo.o

testNodo: testNodo.o NodoGrafo.o
	$(CXX) $(CXXFLAGS) -o testNodo testNodo.o NodoGrafo.o

testPrim: testPrim.o Prim.o Grafo.o NodoGrafo.o HeapFib.o NodoHeapFib.o
	$(CXX) $(CXXFLAGS) -o testPrim testPrim.o Prim.o Grafo.o NodoGrafo.o HeapFib.o NodoHeapFib.o

testHeapFib: testHeapFib.o HeapFib.o NodoHeapFib.o
	$(CXX) $(CXXFLAGS) -o testHeapFib testHeapFib.o HeapFib.o NodoHeapFib.o

testNodoHeapFib: testNodoHeapFib.o NodoHeapFib.o
	$(CXX) $(CXXFLAGS) -o testNodoHeapFib testNodoHeapFib.o NodoHeapFib.o

# Regla para compilar objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos compilados
clean:
	del /Q $(OBJETOS) $(TESTS_OBJETOS) $(PROGRAMA).exe $(addsuffix .exe, $(TESTS))
	@echo Clean done.

# Indica a make que 'clean' no es el nombre de un archivo
.PHONY: all clean