#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include "Nodo.h"

class Grafo {
private:
    std::vector<Nodo*> nodos; // Almacenamos punteros a los nodos del grafo

public:
    Grafo();
    ~Grafo(); // Destructor para liberar la memoria
    void agregarNodo(int id);
    void agregarArista(int id1, int id2, int peso);
    void leerGrafo(const std::string& nombreArchivo);
    void printGrafo() const;
    const std::vector<Nodo*>& getNodos() const;
};

#endif // GRAFO_H