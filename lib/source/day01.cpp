#include "day01.h"

#include <fstream>
#include <iostream>

int Day01::Step(int nCurrentFloor, char charDirection)
{
    switch (charDirection)
    {
        case '(':
            return nCurrentFloor+1;
        case ')':
            return nCurrentFloor-1;
        default:
            return -1;
    }
}

std::vector<char> Day01::ParseDirections(std::string strFilename)
{
    std::ifstream fileInput;
    std::vector<char> vcharDirections;
    char direction;
    
    fileInput.open(strFilename.c_str());
    if(!fileInput.is_open())
    {
        return vcharDirections;
    }

    while(fileInput.get(direction))
    {
        if(direction == '(' || direction == ')')
            vcharDirections.push_back(direction);
    }

    return vcharDirections;
}

int Day01::Part1(std::vector<char> vcharDirections)
{
    int nCurrentFloor = 0;
    
    for(int i = 0; i < vcharDirections.size(); i++)
    {
        nCurrentFloor = Step(nCurrentFloor, vcharDirections[i]);
    }

    return nCurrentFloor;
}

int Day01::Part2(std::vector<char> vcharDirections)
{
    int nCurrentFloor = 0;

    for(int i = 0; i < vcharDirections.size(); i++)
    {
        nCurrentFloor = Step(nCurrentFloor, vcharDirections[i]);
        if(nCurrentFloor == -1)
            return i+1;
    }

    return -1;
}
