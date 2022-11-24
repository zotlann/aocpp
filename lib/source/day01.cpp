#include "day01.h"

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
