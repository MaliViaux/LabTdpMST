#ifndef HEAPFIB_H
#define HEAPFIB_H

#include <functional>
#include <cmath>
#include <vector>
#include <iostream>
#include "NodoHeapFib.h"

/*
    * Representa un heap de fibonacci, una coleccion de arboles con propiedad min-heap,
    * utiliza la clase NodoHeapFib para representar los nodos. Almacena el inicio de una lista
    * doblemente enlazada con las raices de los arboles, el minimo siempre se encuentra en
    * esa lista, los hijos siempre son mayores o iguales a los padres
*/
class HeapFib {
private:
    // Puntero al nodo mínimo del heap
    NodoHeapFib* min;
    // Puntero al inicio de la lista (doblemente enlazada) de raices
    NodoHeapFib* rootsListHead;
    // Número total de nodos en el heap
    int numNodos;

public:
    // costructor
    HeapFib();

    // destructor
    ~HeapFib();

    // getters
    NodoHeapFib* getMin();

    // otros metodos
    NodoHeapFib* insert(int key);
    NodoHeapFib* extractMin();
    void consolidate();
    void decreaseKey(NodoHeapFib* nodo, int nuevoValor);
    void insertRootList(NodoHeapFib* nodo);
    void removeRoot(NodoHeapFib* nodo);
    void mergeHeap(NodoHeapFib* x, NodoHeapFib* y);
    void insertChildList(NodoHeapFib* parent, NodoHeapFib* nodo);
    void cut(NodoHeapFib* child,  NodoHeapFib* parent);
    void removeChild(NodoHeapFib* child, NodoHeapFib* parent);
    void cascadingCut(NodoHeapFib* parent);
    bool isEmpty() const;
    void printHeap(NodoHeapFib* nodo, NodoHeapFib* min, int depth);
    void printHeapMinimum();
};

#endif // HEAPFIB_H