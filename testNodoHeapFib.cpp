#include <iostream>
#include "NodoHeapFib.h"

int main() {
    // se testean los métodos getKey, getParent, setKey, setMark, setParent y isMarked
    // el resto de los metodos tienen la misma logica, por lo que si estos funcionan
    // los otros tambien

    // Crear dos nodos
    NodoHeapFib* nodo1 = new NodoHeapFib(10);
    NodoHeapFib* nodo2 = new NodoHeapFib(20);

    // Test getKey
    std::cout << "El valor de nodo1 es: " << nodo1->getKey() << std::endl;
    std::cout << "El valor de nodo2 es: " << nodo2->getKey() << std::endl;

    // Test getParent y setParent
    nodo1->setParent(nodo2);
    std::cout << "El padre de nodo1 ahora tiene el valor: " << (nodo1->getParent() ? nodo1->getParent()->getKey() : -1) << std::endl;

    // Test setKey
    nodo1->setKey(15); // Cambia el valor del nodo1 a 15
    std::cout << "El nuevo valor de nodo1 es: " << nodo1->getKey() << std::endl;

    // Test setMark y isMarked
    nodo1->setMark(true); // Marca el nodo1
    std::cout << "nodo1 " << (nodo1->isMarked() ? "está" : "no está") << " marcado." << std::endl;

    // Limpiar la memoria
    delete nodo1;
    delete nodo2;

    return 0;
}