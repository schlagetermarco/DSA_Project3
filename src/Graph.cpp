
#include "Graph.h"

void Graph::buildGraph(const std::vector<EdgeList> &edges) {
    for (const auto & e: edges) {
        Edge edge;
        edge.target = e.locationIdTwo;
        edge.weight = e.time;
        adjList[e.locationIdOne].push_back(edge);
        edge.target = e.locationIdOne;
        adjList[e.locationIdTwo].push_back(edge);
    }
}
