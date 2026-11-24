#include "CampusCompass.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>


using namespace std;

CampusCompass::CampusCompass() {
}

bool CampusCompass::ParseCSV(const string &edges_filepath, const string &classes_filepath) {
    ifstream classesFile(classes_filepath);
    if (!classesFile.is_open()) {
        cout<<"Error opening file: "<<classes_filepath<<endl;
        return false;
    }
    string line;
    getline(classesFile,line);
    while (getline(classesFile, line)) {
        istringstream lineStream(line);
        Classes classObj;

        getline(lineStream,classObj.classCode,',');
        string num;
        getline(lineStream,num,',');
        classObj.locationID = stoi(num);
        getline(lineStream,classObj.startTime,',');
        getline(lineStream,classObj.endTime,',');
        classes.push_back(classObj);
    }

    ifstream edgesFile(edges_filepath);
    if (!edgesFile.is_open()) {
        cout<<"Error opening file: "<<edges_filepath<<endl;
        return false;
    }

    getline(edgesFile,line);
    while (getline(edgesFile, line)) {
        istringstream lineStream(line);
        EdgeList edgesObj;
        string num;
        string numTwo;
        getline(lineStream,num,',');
        getline(lineStream,numTwo,',');
        edgesObj.locationIdOne = stoi(num);
        edgesObj.locationIdTwo = stoi(numTwo);
        getline(lineStream,edgesObj.nameOne,',');
        getline(lineStream,edgesObj.nameTwo,',');
        string timeToTravel;
        getline(lineStream,timeToTravel,',');
        edgesObj.time = stoi(timeToTravel);
        edgeList.push_back(edgesObj);
    }
    graph.buildGraph(edgeList);
    return true;
}

bool CampusCompass::ParseCommand(const string &command) {
    // do whatever regex you need to parse validity
    // hint: return a boolean for validation when testing. For example:
    bool is_valid = true; // replace with your actual validity checking

    return is_valid;
}

bool CampusCompass::insert(const std::string &name, const std::string &ID, int residence, int classCount,
    const std::vector<std::string> &classCodes) {
    if (classCount<1 || classCount>6 || static_cast<size_t>(classCount)!=classCodes.size()){
        return false;
    }
    if (students.count(ID)) {
        return false;
    }

    if (ID.size() != 8) {
        return false;
    }

    for (size_t i=0; i<ID.size(); i++) {
        if (!isdigit(ID[i])) {
            return false;
        }
    }

    Student student;
    student.studentID = ID;
    student.name = name;
    student.residenceLocationID = residence;

    for (auto code : classCodes) {
        student.classCodes.push_back(code);
    }

    students[ID] = student;
    return true;
}
