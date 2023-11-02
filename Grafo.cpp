#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Grafo.h"

Grafo::Grafo() {}

Grafo::~Grafo() {
    for(Nodo* nodo : nodos) {
        delete nodo; // Libera la memoria de cada nodo
    }
}

void Grafo::agregarNodo(int id) {
    nodos.push_back(new Nodo(id));
}

void Grafo::agregarArista(int id1, int id2, int peso) {
    nodos[id1]->agregarAdyacente(nodos[id2], peso);
    nodos[id2]->agregarAdyacente(nodos[id1], peso);
}

void Grafo::leerGrafo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    int numNodos = 0;

    // Contar el número de líneas para saber cuántos nodos hay
    while (std::getline(archivo, linea)) {
        numNodos++;
    }

    // Crear los nodos
    for (int i = 0; i < numNodos; ++i) {
        agregarNodo(i);
    }

    archivo.clear();
    archivo.seekg(0, std::ios::beg);

    int idOrigen = 0;
    // Leer las aristas
    while (std::getline(archivo, linea)) {
        std::istringstream lineaStream(linea);
        int peso;
        int idDestino = 0;

        while (lineaStream >> peso) {
            if (idOrigen < idDestino && peso != 0) { // Ignorar la diagonal y el triángulo inferior
                agregarArista(idOrigen, idDestino, peso);
            }
            idDestino++;
        }
        idOrigen++;
    }

    archivo.close();
}

void Grafo::printGrafo() const {
    for(const auto& nodo : nodos) {
        std::cout << "Nodo " << nodo->getId() << ": ";
        for (const auto& par : nodo->getAdyacentes()) {
            std::cout << "(" << par.first->getId() << ", " << par.second << ") ";
        }
        std::cout << std::endl;
    }
}