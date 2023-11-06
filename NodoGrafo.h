#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

/*
    * Representa un nodo a traves de un identificador 
    * unico y un vector de pares con los nodos  
    * adyacentes y el peso de esa arista
*/
class NodoGrafo {
private:
    // id del nodo
    int id;
    // vector de pares con el nodo adyacente y el peso
    std::vector<std::pair<NodoGrafo*, int>> adyacentes;
public:
    // constructor
    NodoGrafo(int id);

    // getters
    int getId() const;

    const std::vector<std::pair<NodoGrafo*, int>>& getAdyacentes() const;
    
    // otros metodos
    void agregarAdyacente(NodoGrafo* nodo, int peso);
    void printAdyacentes() const;
};

#endif // NODO_H