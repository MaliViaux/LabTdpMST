#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include "NodoGrafo.h"

/*
    * La clase Grafo representa un grafo no dirigido con una lista de nodos clase NodoGrafo. 
    * Permite agregar nodos y aristas y tiene la capacidad de leer un grafo desde un archivo.
*/
class Grafo {
private:
    // vector de punteros a los nodos del grafo
    std::vector<NodoGrafo*> nodos;
public:
    // constructor
    Grafo();

    // destructor
    ~Grafo();

    // getters
    const std::vector<NodoGrafo*>& getNodos() const;

    // otros metodos
    void agregarNodo(int id);
    void agregarArista(int id1, int id2, int peso);
    bool leerGrafo(const std::string& nombreArchivo);
    void printGrafo() const;
    int getPesoArista(int id1, int id2) const;
};

#endif // GRAFO_H