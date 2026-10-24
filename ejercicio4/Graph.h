#ifndef PATRONESDISENIO_GRAPH_H
#define PATRONESDISENIO_GRAPH_H

#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <memory>

class Node {
public:
    explicit Node(int id);
    int getId() const;

private:
    int id_;
};

// Interfaz del Iterador
class GraphIterator {
public:
    virtual ~GraphIterator()= default;
    virtual bool hasNext()= 0;
    virtual int next()= 0;
};

// Forward declaration
class Graph;

class BFSIterator final: public GraphIterator {
public:
    BFSIterator(const Graph& graph, int startId);
    bool hasNext() override;
    int next() override;

private:
    const Graph& graph_;
    std::queue<int> queue_;
    std::unordered_set<int> visited_;
};

class DFSIterator final: public GraphIterator {
public:
    DFSIterator(const Graph& graph, int startId);
    bool hasNext() override;
    int next() override;

private:
    const Graph& graph_;
    std::stack<int> stack_;
    std::unordered_set<int> visited_;
};

class Graph {
public:
    Graph()= default;
    void addEdge(int from, int to);
    const std::vector<int>& getNeighbors(int node) const;
    bool hasNode(int node) const;

private:
    std::unordered_map<int, std::vector<int>> adjList_;
    static const std::vector<int> emptyList_;
};

#endif //PATRONESDISENIO_GRAPH_H