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
