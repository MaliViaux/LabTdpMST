#include "Grafo.h"

int main() {
    Grafo grafo;

    // Test agregarNodo y buscarNodo
    grafo.agregarNodo(1);
    grafo.agregarNodo(2);
    grafo.agregarNodo(3);

    // Test agregarArista
    grafo.agregarArista(1, 2, 10);
    grafo.agregarArista(2, 3, 20);
    grafo.agregarArista(3, 1, 30);

    grafo.printGrafo();

    Grafo grafo1;

    // Test leerGrafo
    grafo1.leerGrafo("matrix.txt"); // Asegúrate de tener un archivo con este nombre y el formato correcto

    // Imprimir el grafo para verificar que se leyó correctamente
    grafo1.printGrafo();

    return 0;
}