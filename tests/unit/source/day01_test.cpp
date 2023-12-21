#include "day01.h"
#include <gtest/gtest.h>
 
TEST(Day01Test, Ascend)
{ 
    char charAscend='(';
    ASSERT_EQ(0, Day01::Step(-1, charAscend));
    ASSERT_EQ(1, Day01::Step(0, charAscend));
    ASSERT_EQ(2, Day01::Step(1, charAscend));
}

TEST(Day01Test, Descend)
{
    char charDescend=')';
    ASSERT_EQ(0, Day01::Step(1, charDescend));
    ASSERT_EQ(1, Day01::Step(2, charDescend));
    ASSERT_EQ(-2, Day01::Step(-1, charDescend));
}

TEST(Day01Test, InvalidDirection)
{
    char charInvalid='?';
    ASSERT_EQ(-1, Day01::Step(1, charInvalid));
    ASSERT_EQ(-1, Day01::Step(0, charInvalid));
    ASSERT_EQ(-1, Day01::Step(-1, charInvalid));
}

TEST(Day01Test, ParseFile)
{
    char pcharCase1[5] = "(())";
    char pcharCase2[4] = "(((";
    char pcharCase3[8] = "))(((((";

    std::string strFilenameCase1("data/case1.txt");
    std::string strFilenameCase2("data/case2.txt");
    std::string strFilenameCase3("data/case3.txt");
    std::string strFilenameInavlid("asdf");

    std::vector<char> vcharCase1(pcharCase1, pcharCase1+4);
    std::vector<char> vcharCase2(pcharCase2, pcharCase2+3);
    std::vector<char> vcharCase3(pcharCase3, pcharCase3+7);
    std::vector<char> vcharInvalid;

    ASSERT_EQ(vcharCase1, Day01::ParseDirections(strFilenameCase1));
    ASSERT_EQ(vcharCase2, Day01::ParseDirections(strFilenameCase2));
    ASSERT_EQ(vcharCase3, Day01::ParseDirections(strFilenameCase3));
    ASSERT_EQ(vcharInvalid, Day01::ParseDirections(strFilenameInavlid));
}

TEST(Day01Test, Part1)
{    
    char pcharCase1[5] = "(())";
    char pcharCase2[4] = "(((";
    char pcharCase3[8] = "))(((((";
    char pcharCase4[4] = ")))";

    std::vector<char> vcharCase1(pcharCase1, pcharCase1+4);
    std::vector<char> vcharCase2(pcharCase2, pcharCase2+3);
    std::vector<char> vcharCase3(pcharCase3, pcharCase3+7);
    std::vector<char> vcharCase4(pcharCase4, pcharCase4+3);

    ASSERT_EQ(0, Day01::Part1(vcharCase1));
    ASSERT_EQ(3, Day01::Part1(vcharCase2));
    ASSERT_EQ(3, Day01::Part1(vcharCase3));
    ASSERT_EQ(-3, Day01::Part1(vcharCase4));
}

TEST(Day01Test, Part2)
{
    char pcharCase1[2] = ")";
    char pcharCase2[6] = "()())";
    char pcharCase3[2] = "(";

    std::vector<char> vcharCase1(pcharCase1, pcharCase1+1);
    std::vector<char> vcharCase2(pcharCase2, pcharCase2+5);
    std::vector<char> vcharCase3(pcharCase3, pcharCase3+1);

    ASSERT_EQ(1, Day01::Part2(vcharCase1));
    ASSERT_EQ(5, Day01::Part2(vcharCase2));
    ASSERT_EQ(-1, Day01::Part2(vcharCase3));

}
