#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

class Nodo {
private:
    int id;
    std::vector<std::pair<Nodo*, int>> adyacentes;

public:
    Nodo(int id);
    void agregarAdyacente(Nodo* nodo, int peso); //
    int getId() const;
    const std::vector<std::pair<Nodo*, int>>& getAdyacentes() const;
    void printAdyacentes() const;
};

#endif // NODO_H