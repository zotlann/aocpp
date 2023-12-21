#include "day01.h"
#include <gtest/gtest.h>
 
TEST(Day01Test, Part1FullFile)
{
    std::string strFilename("data/input.txt");
    std::vector<char> vcharDirections = Day01::ParseDirections(strFilename.c_str());

    ASSERT_EQ(138, Day01::Part1(vcharDirections));
}

TEST(Day01Test, Part2FullFile)
{
    std::string strFilename("data/input.txt");
    std::vector<char> vcharDirections = Day01::ParseDirections(strFilename.c_str());

    ASSERT_EQ(1771, Day01::Part2(vcharDirections));
}
