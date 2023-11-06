#include "Grafo.h"

int main() {
    Grafo grafo;

    // Test agregarNodo y buscarNodo
    grafo.agregarNodo(0);
    grafo.agregarNodo(1);
    grafo.agregarNodo(2);

    // Test agregarArista
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(1, 2, 20);
    grafo.agregarArista(2, 0, 30);

    grafo.printGrafo();

    Grafo grafo1;

    // Test leerGrafo
    // Lee el grafo desde el archivo especificado
    if (!grafo1.leerGrafo("matrix20.txt")) {
        return 1; // Finaliza el programa si no se pudo leer el archivo
    }
    // Imprimir el grafo para verificar que se leyó correctamente
    grafo1.printGrafo();

    return 0;
}