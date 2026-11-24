#pragma once
#include <string>
#include <vector>
#include "dataLoader.h"
#include "Graph.h"
#include "Student.h"

using namespace std;

class CampusCompass {
private:
    std::vector<Classes> classes;
    std::vector<EdgeList> edgeList;
    std::unordered_map<std::string, Student> students;
    Graph graph;
public:
    // Think about what helper functions you will need in the algorithm
    CampusCompass(); // constructor
    bool ParseCSV(const string &edges_filepath, const string &classes_filepath);
    bool ParseCommand(const string &command);
    bool insert(const std::string &name, const std::string &ID, int residence, int classCount,
        const std::vector<std::string> &classCodes);
};
