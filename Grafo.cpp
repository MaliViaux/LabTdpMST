#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Grafo.h"

/**
     * @brief Constructor por defecto de la clase Grafo.
     */
Grafo::Grafo() {}

/**
     * @brief Destructor de la clase Grafo.
     *
     * Libera la memoria asignada a los nodos del grafo.
     */
Grafo::~Grafo() {
    for(NodoGrafo* nodo : nodos) {
        delete nodo; // Libera la memoria de cada nodo
    }
}

/**
     * @brief Agrega un nuevo nodo al grafo con el id especificado.
     *
     * @param id Identificador único del nuevo nodo.
     */
void Grafo::agregarNodo(int id) {
    nodos.push_back(new NodoGrafo(id));
}

/**
     * @brief Agrega una arista no dirigida entre dos nodos en el grafo.
     *
     * @param id1 Identificador del primer nodo de la arista.
     * @param id2 Identificador del segundo nodo de la arista.
     * @param peso Peso de la arista entre los nodos.
     */
void Grafo::agregarArista(int id1, int id2, int peso) {
    nodos[id1]->agregarAdyacente(nodos[id2], peso);
    nodos[id2]->agregarAdyacente(nodos[id1], peso);
}

/**
     * @brief Lee un grafo desde un archivo.
     *
     * Este método asume que el archivo contiene una matriz de adyacencia.
     *
     * @param nombreArchivo El nombre del archivo a leer.
     * @return true si el grafo fue leído exitosamente, false en caso contrario.
     */
bool Grafo::leerGrafo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return false;
    }
    std::string linea;
    int idOrigen = 0;
    // Leer las aristas y crear los nodos al mismo tiempo
    while (std::getline(archivo, linea)) {
        std::istringstream lineaStream(linea);
        int peso;
        int idDestino = 0;

        while (lineaStream >> peso) {
            if (idOrigen == 0){
                agregarNodo(idDestino);
            }
            if (idOrigen < idDestino && peso != 0) {
                agregarArista(idOrigen, idDestino, peso);
            }
            idDestino++;
        }
        idOrigen++;
    }
    archivo.close();
    return true;
}

/**
     * @brief Obtiene la lista de nodos del grafo.
     *
     * @return const std::vector<NodoGrafo*>& Una referencia constante al vector de nodos.
     */
const std::vector<NodoGrafo*>& Grafo::getNodos() const {
    return nodos;
}

/**
     * @brief Imprime una representación del grafo a la salida estándar.
     *
     * Muestra cada nodo y sus adyacencias con los respectivos pesos de las aristas.
     */
void Grafo::printGrafo() const {
    for(const auto& nodo : nodos) {
        std::cout << "NodoGrafo " << nodo->getId() << ": ";
        for (const auto& par : nodo->getAdyacentes()) {
            std::cout << "(" << par.first->getId() << ", " << par.second << ") ";
        }
        std::cout << std::endl;
    }
}

/**
     * @brief Obtiene el peso de la arista entre dos nodos.
     *
     * @param id1 Identificador del primer nodo.
     * @param id2 Identificador del segundo nodo.
     * @return int El peso de la arista, o -1 si los nodos no están directamente conectados.
     */
int Grafo::getPesoArista(int id1, int id2) const {
    // Busca el nodo con id1
    for (NodoGrafo* nodo : nodos) {
        if (nodo->getId() == id1) {
            // Recorre la lista de adyacentes para id1
            for (const auto& adyacente : nodo->getAdyacentes()) {
                if (adyacente.first->getId() == id2) {
                    return adyacente.second;
                }
            }
            break;
        }
    }
    return -1;
}
