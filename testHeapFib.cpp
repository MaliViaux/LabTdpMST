#include "HeapFib.h"

int main() {
    HeapFib* heap = new HeapFib();
    
    // Insertar elementos en el heap
    std::vector<NodoHeapFib*> nodes;
    nodes.push_back(heap->insert(10));
    nodes.push_back(heap->insert(20));
    nodes.push_back(heap->insert(30));
    nodes.push_back(heap->insert(8));
    nodes.push_back(heap->insert(7));
    nodes.push_back(heap->insert(100));
    nodes.push_back(heap->insert(50));
    nodes.push_back(heap->insert(38));
    nodes.push_back(heap->insert(22));
    nodes.push_back(heap->insert(40));
    nodes.push_back(heap->insert(60));

    std::cout << "Despues de las inserciones:" << std::endl;
    heap->printHeapMinimum();

    // Disminuir la clave de un nodo y extraer el mínimo
    heap->decreaseKey(nodes[3], 5);  // Disminuir la clave del segundo nodo insertado a 5
    std::cout << "Despues de decreaseKey:" << std::endl;
    heap->printHeapMinimum(); // Nuevamente, solo imprimimos el mínimo

    heap->decreaseKey(nodes[5], 1);  // Disminuir la clave del segundo nodo insertado a 5
    std::cout << "Despues de decreaseKey:" << std::endl;
    heap->printHeapMinimum(); // Nuevamente, solo imprimimos el mínimo

    // Continuar extrayendo el mínimo para probar extractMin
    std::cout << "Extrayendo minimos:" << std::endl;
    while (!heap->isEmpty()) {
        //heap->printHeap(nodes[0], heap->getMin(), 0);
        NodoHeapFib* minNode = heap->extractMin(); // Aquí extraemos y luego imprimimos
        //heap->printHeap(nodes[0], heap->getMin(), 0);
        if (minNode != nullptr) {
            std::cout << "El minimo extraido del heap es: " << minNode->getKey() << std::endl;
        }
    }
}
