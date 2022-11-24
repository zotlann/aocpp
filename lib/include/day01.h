#ifndef _DAY01_H
#define _DAY01_H

#include <vector>
#include <string>

namespace Day01
{
/// Move up a floor if charDirection is (
/// Move down a floor if charDirectoin is )
/// return the resulting floor
/// if charDirection is invalid, return -1
int Step(int nCurrentFloor, char charDirection);

/// Parse the file at the given filename
/// Returns a vector of directions
std::vector<char> ParseDirections(std::string strFilename);

/// Solve part 1 given the directions
int Part1(std::vector<char> vcharDirections);

/// Solve part 2 given the directions
/// If santa never enters the basement, return -1
int Part2(std::vector<char> vcharDirections);

};

#endif
