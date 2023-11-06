#include <chrono>
#include "Prim.h"

int main() {
    // Solicita al usuario el nombre del archivo
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::getline(std::cin, nombreArchivo);

    Grafo grafo;
    
    // Lee el grafo
    if (!grafo.leerGrafo(nombreArchivo)) {
        return 1;
    }

    Prim prim;

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> mst = prim.construirMST(grafo);

    auto end = std::chrono::high_resolution_clock::now();
    
    // Calcula la diferencia de tiempo
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //prim.imprimirMST(mst, grafo);

    std::cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << std::endl;


    return 0;
}