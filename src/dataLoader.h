#pragma once
#include <string>

struct EdgeList {
    int locationIdOne;
    int locationIdTwo;
    std::string nameOne;
    std::string nameTwo;
    int time;
};

struct Classes {
    std::string classCode;
    int locationID;
    std::string startTime;
    std::string endTime;
};
