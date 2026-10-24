#include <iostream>
#include <memory>
#include "Graph.h"

int main() {
    std::cout << "=== Ejercicio 4: Iterator - Recorrido de Grafo ===\n";

    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    std::cout<< "Recorrido BFS iniciando en 1: ";
    std::unique_ptr<GraphIterator> it= std::make_unique<BFSIterator>(g, 1);
    while (it->hasNext()) {
        std::cout<< it->next()<<" ";
    }
    std::cout<< "\n";

    std::cout<< "Recorrido DFS iniciando en 1 (cambio dinamico): ";
    it= std::make_unique<DFSIterator>(g, 1);
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    std::cout << "\n";

    return 0;
}