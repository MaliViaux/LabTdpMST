#ifndef PRIM_H
#define PRIM_H

#include <climits>
#include "HeapFib.h"
#include "Grafo.h"

/*
    * La clase Prim implementa el algoritmo de Prim para encontrar el MST de un grafo.
    * Esta clase utiliza un Heap de Fibonacci para seleccionar eficientemente
    * la siguiente arista de menor peso que no forme un ciclo y que
    * conecte un nuevo vértice al árbol en construcción.
*/
class Prim {
private:
    HeapFib* fibHeap;
    int costoMST;
public:
    // constructor
    Prim();

    // destructor
    ~Prim();

    // getters
    int getCostoMST();

    // otros metodos
    std::vector<int> construirMST(Grafo& grafo);
    void imprimirMST(const std::vector<int>& mst, Grafo& grafo);
};

#endif // PRIM_H