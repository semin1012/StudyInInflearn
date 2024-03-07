#include "Helper.h"
#include <iostream>
using namespace std;

int GTest;

void Test(int)
{
    Test2();
}

void Test2()
{
    cout << "Hello World" << endl;
}