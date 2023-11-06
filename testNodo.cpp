#include "NodoGrafo.h"

int main() {
    // Crear nodos
    NodoGrafo nodo1(1);
    NodoGrafo nodo2(2);
    NodoGrafo nodo3(3);
    NodoGrafo nodo4(4);

    // Agregar adyacentes
    nodo1.agregarAdyacente(&nodo2, 10);
    nodo1.agregarAdyacente(&nodo3, 5);
    nodo1.agregarAdyacente(&nodo4, 20);

    nodo2.agregarAdyacente(&nodo1, 10);
    nodo2.agregarAdyacente(&nodo4, 15);
    nodo2.agregarAdyacente(&nodo3, 12);

    nodo3.agregarAdyacente(&nodo4, 18);
    nodo3.agregarAdyacente(&nodo1, 5);
    nodo3.agregarAdyacente(&nodo2, 12);

    nodo4.agregarAdyacente(&nodo1, 20);
    nodo4.agregarAdyacente(&nodo3, 18);
    nodo4.agregarAdyacente(&nodo2, 15);

    // Imprimir adyacentes para verificar que están ordenados
    nodo1.printAdyacentes();
    nodo2.printAdyacentes();
    nodo3.printAdyacentes();
    nodo4.printAdyacentes();

    // Probar getId
    if (nodo1.getId() != 1 || nodo2.getId() != 2 || nodo3.getId() != 3) {
        std::cout << "Error en getId()" << std::endl;
    } else {
        std::cout << "getId() funciona correctamente" << std::endl;
    }

    // Probar getAdyacentes
    const auto& adyacentes = nodo1.getAdyacentes();
    if (adyacentes.size() != 3 || 
    adyacentes[0].first->getId() != 3 || adyacentes[0].second != 5 ||
    adyacentes[1].first->getId() != 2 || adyacentes[1].second != 10 ||
    adyacentes[2].first->getId() != 4 || adyacentes[2].second != 20) {
        std::cout << "Error en getAdyacentes()" << std::endl;
    } else {
        std::cout << "getAdyacentes() funciona correctamente" << std::endl;
    }

    return 0;
}