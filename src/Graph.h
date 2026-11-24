#pragma once
#include <unordered_map>
#include <vector>
#include "dataLoader.h"

struct Edge {
    int target;
    int weight;
    bool closed = false;
};

class Graph {
    std::unordered_map<int,std::vector<Edge>> adjList;
public:
    void buildGraph(const std::vector<EdgeList> &edges);

};
