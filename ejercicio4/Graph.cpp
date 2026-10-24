#include "Graph.h"
#include <stdexcept>

//Node
Node::Node(int id) : id_(id) {}
int Node::getId() const { return id_;}

//Graph
const std::vector<int> Graph::emptyList_= {};

void Graph::addEdge(int from, int to) {
    adjList_[from].push_back(to);
    if (adjList_.find(to)== adjList_.end()) {
        adjList_[to]= {};
    }
}

const std::vector<int>& Graph::getNeighbors(int node) const {
    auto it= adjList_.find(node);
    if (it!= adjList_.end()) {
        return it->second;
    }
    return emptyList_;
}

bool Graph::hasNode(int node) const {
    return adjList_.find(node)!= adjList_.end();
}

//BFSIterator
BFSIterator::BFSIterator(const Graph& graph, int startId): graph_(graph) {
    if (graph_.hasNode(startId)) {
        queue_.push(startId);
        visited_.insert(startId);
    }
}

bool BFSIterator::hasNext() {
    return !queue_.empty();
}

int BFSIterator::next() {
    if (!hasNext()) {
        throw std::out_of_range("No hay mas elementos en el iterador BFS");
    }
    int current= queue_.front();
    queue_.pop();

    for (int neighbor: graph_.getNeighbors(current)) {
        if (visited_.find(neighbor)== visited_.end()) {
            visited_.insert(neighbor); //Previene ciclos infinitos
            queue_.push(neighbor);
        }
    }
    return current;
}

//DFSIterator
DFSIterator::DFSIterator(const Graph& graph, int startId): graph_(graph) {
    if (graph_.hasNode(startId)) {
        stack_.push(startId);
    }
}

bool DFSIterator::hasNext() {
    while (!stack_.empty() && visited_.find(stack_.top())!= visited_.end()) {
        stack_.pop();
    }
    return !stack_.empty();
}

int DFSIterator::next() {
    if (!hasNext()) {
        throw std::out_of_range("No hay mas elementos en el iterador DFS");
    }
    int current= stack_.top();
    stack_.pop();
    visited_.insert(current); //Previene ciclos infinitos

    const auto& neighbors= graph_.getNeighbors(current);
    // Recorrido inverso en pila para procesar vecinos en orden ascendente natural
    for (auto it= neighbors.rbegin(); it!= neighbors.rend(); ++it) {
        if (visited_.find(*it)== visited_.end()) {
            stack_.push(*it);
        }
    }
    return current;
}