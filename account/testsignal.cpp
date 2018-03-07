#include "testsignal.h"

TestSignal::TestSignal()
{
number = 0;
}

void TestSignal::setNum(int n)
{
    number = n;
}
int TestSignal::getNum()
{
    return number;
}
