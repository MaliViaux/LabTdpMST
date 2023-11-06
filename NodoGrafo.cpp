#include "NodoGrafo.h"

/**
 * @brief Constructor de la clase NodoGrafo.
 *
 * Inicializa un nuevo nodo de grafo con un identificador específico.
 *
 * @param id El identificador único para el nodo del grafo.
 */
NodoGrafo::NodoGrafo(int id) : id(id) {}

void NodoGrafo::agregarAdyacente(NodoGrafo* nodo, int peso) {
    adyacentes.push_back(std::make_pair(nodo, peso));
}

/**
 * @brief Obtiene el identificador del nodo.
 *
 * @return int El identificador del nodo.
 */
int NodoGrafo::getId() const {
    return id;
}

/**
 * @brief Obtiene el vector de nodos adyacentes y pesos asociados a este nodo.
 *
 * @return const std::vector<std::pair<NodoGrafo*, int>>& Una referencia constante al vector de pares
 * que contiene los nodos adyacentes y sus respectivos pesos.
 */
const std::vector<std::pair<NodoGrafo*, int>>& NodoGrafo::getAdyacentes() const {
    return adyacentes;
}

/**
 * @brief Imprime los nodos adyacentes y los pesos de las aristas asociadas a este nodo.
 *
 * Muestra en consola todos los nodos que están directamente conectados con este nodo y el peso
 * de cada una de las aristas que forman la conexión.
 */
void NodoGrafo::printAdyacentes() const {
    std::cout << "NodoGrafo " << id << ": ";
    for (const auto& par : adyacentes) {
        std::cout << "(" << par.first->getId() << ", " << par.second << ") ";
    }
    std::cout << std::endl;
}