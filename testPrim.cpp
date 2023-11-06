#include "Prim.h"

int main() {
    // Crea una instancia de Grafo y añade nodos y aristas
    Grafo grafo;
    Grafo grafo1;
    
    grafo.agregarNodo(0);
    grafo.agregarNodo(1);
    grafo.agregarNodo(2);
    grafo.agregarNodo(3);
    grafo.agregarNodo(4);
    grafo.agregarNodo(5);
    grafo.agregarNodo(6);
    grafo.agregarNodo(7);
    grafo.agregarNodo(8);
    grafo.agregarNodo(9);
    grafo.agregarArista(0, 1, 9);
    grafo.agregarArista(0, 2, 9);
    grafo.agregarArista(0, 3, 8);
    grafo.agregarArista(0, 9, 18);
    grafo.agregarArista(1, 2, 3);
    grafo.agregarArista(2, 3, 9);
    grafo.agregarArista(4, 2, 2);
    grafo.agregarArista(5, 2, 4);
    grafo.agregarArista(1, 5, 6);
    grafo.agregarArista(4, 3, 8);
    grafo.agregarArista(3, 6, 7);
    grafo.agregarArista(4, 6, 9);
    grafo.agregarArista(5, 6, 9);
    grafo.agregarArista(3, 8, 9);
    grafo.agregarArista(3, 9, 10);
    grafo.agregarArista(6, 7, 4);
    grafo.agregarArista(6, 8, 5);
    grafo.agregarArista(7, 8, 1);
    grafo.agregarArista(7, 9, 4);
    grafo.agregarArista(8, 9, 3);
    grafo.agregarArista(5, 4, 2);

    grafo1.agregarNodo(0);
    grafo1.agregarNodo(1);
    grafo1.agregarNodo(2);
    grafo1.agregarNodo(3);
    grafo1.agregarNodo(4);
    grafo1.agregarNodo(5);
    grafo1.agregarNodo(6);
    grafo1.agregarNodo(7);
    grafo1.agregarNodo(8);
    grafo1.agregarNodo(9);
    grafo1.agregarArista(2, 1, 3);
    grafo1.agregarArista(3, 1, 2);
    grafo1.agregarArista(7, 3, 1);
    grafo1.agregarArista(0, 9, 13);
    grafo1.agregarArista(0, 8, 9);
    grafo1.agregarArista(2, 4, 16);
    grafo1.agregarArista(4, 7, 11);
    grafo1.agregarArista(5, 2, 17);
    grafo1.agregarArista(8, 5, 18);
    grafo1.agregarArista(3, 6, 7);
    grafo1.agregarArista(4, 8, 4);
    grafo1.agregarArista(3, 6, 7);
    grafo1.agregarArista(6, 7, 6);
    grafo1.agregarArista(6, 9, 15);
    grafo1.agregarArista(7, 8, 10);
    grafo1.agregarArista(7, 9, 5);
    grafo1.agregarArista(8, 9, 12);
    grafo1.agregarArista(5, 4, 8);



    // Crea una instancia de Prim
    Prim prim;

    // Construir MST con el algoritmo de Prim
    std::vector<int> mst = prim.construirMST(grafo);
    std::vector<int> mst2 = prim.construirMST(grafo1);
    prim.imprimirMST(mst, grafo);
    prim.imprimirMST(mst2, grafo1);
}