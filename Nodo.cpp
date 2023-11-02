#include "Nodo.h"

Nodo::Nodo(int id) : id(id) {}

void Nodo::agregarAdyacente(Nodo* nodo, int peso) {
    adyacentes.push_back(std::make_pair(nodo, peso));
}

int Nodo::getId() const {
    return id;
}

const std::vector<std::pair<Nodo*, int>>& Nodo::getAdyacentes() const {
    return adyacentes;
}

void Nodo::printAdyacentes() const {
    std::cout << "Nodo " << id << ": ";
    for (const auto& par : adyacentes) {
        std::cout << "(" << par.first->getId() << ", " << par.second << ") ";
    }
    std::cout << std::endl;
}