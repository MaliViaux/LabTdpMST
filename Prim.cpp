#include "Prim.h"

/**
 * @brief Constructor de la clase Prim.
 *
 * Inicializa un nuevo heap de Fibonacci para usar en el algoritmo de Prim y establece el costo del MST a 0.
 */
Prim::Prim() : fibHeap(new HeapFib), costoMST(0) {}


/**
 * @brief Destructor de la clase Prim.
 *
 * Se encarga de liberar la memoria del heap de Fibonacci utilizado para construir el MST.
 */
Prim::~Prim() {
    delete fibHeap;
}

/**
 * @brief Construye el MST a partir de un grafo dado.
 *
 * Este método inicializa las estructuras necesarias y procede a construir el MST usando el algoritmo de Prim.
 * Inicializa todas las claves (key) de los nodos a infinito y comienza desde el nodo 0, estableciendo su clave a 0
 * para asegurarse de que sea el primer nodo en ser extraído del heap de Fibonacci.
 *
 * @param grafo Referencia al grafo sobre el cual se construirá el MST.
 * @return std::vector<int> Un vector que contiene los índices de los nodos padres para cada nodo en el MST.
 */
std::vector<int> Prim::construirMST(Grafo& grafo) {
    int numVertices = grafo.getNodos().size();
    std::vector<int> parent(numVertices, -1);
    std::vector<int> key(numVertices, INT_MAX);
    std::vector<bool> inMST(numVertices, false);
    this->costoMST = 0;
    // Inicializar todos los nodos en el heap con un valor infinito
    std::vector<NodoHeapFib*> heapNodes(numVertices, nullptr);
    for (int i = 0; i < numVertices; ++i) {
        heapNodes[i] = fibHeap->insert(INT_MAX);
        heapNodes[i]->setData(i);
    }
    // Establece la clave del nodo de inicio a 0 para que sea el primer nodo en ser extraído
    fibHeap->decreaseKey(heapNodes[0], 0);
    key[0] = 0;
    while (!fibHeap->isEmpty()) {
        NodoHeapFib* minNode = fibHeap->extractMin();
        int u = minNode->getData(); // u es el índice del nodo actual en el grafo
        delete minNode;
        inMST[u] = true;
        if (u != 0) { // Si no es el primer nodo (que no tiene padre)
            this->costoMST += key[u];
        }
        for (const auto& parAdyacente : grafo.getNodos()[u]->getAdyacentes()) {
            NodoGrafo* nodoV = parAdyacente.first;
            int v = nodoV->getId();
            int weight = parAdyacente.second;
            if (!inMST[v] && weight < key[v]) {
                // Aquí se selecciona una nueva arista para el MST
                parent[v] = u;
                key[v] = weight;
                fibHeap->decreaseKey(heapNodes[v], weight);
            }
        }
    }
    return parent;
}

/**
 * @brief Imprime las aristas del MST y su costo total.
 *
 * @param mst Vector que contiene los índices de los nodos padres de cada nodo en el MST.
 * @param grafo Referencia al grafo del cual se ha construido el MST.
 */
void Prim::imprimirMST(const std::vector<int>& mst, Grafo& grafo) {
    int costoTotalMST = 0;
    for (size_t i = 1; i < mst.size(); ++i) {
        if (mst[i] != -1) { // Si el nodo tiene padre
            int pesoArista = grafo.getPesoArista(mst[i], i);
            costoTotalMST += pesoArista;
            std::cout << "Insertar arista (" << mst[i] << " - " << i << ") con peso " << pesoArista << std::endl;
        }
    }
    std::cout << "Costo total del MST: " << costoTotalMST << std::endl;
}

/**
 * @brief Obtiene el costo total del MST calculado por el algoritmo.
 *
 * @return int El costo total del MST.
 */
int Prim::getCostoMST(){
    return this->costoMST;
}
