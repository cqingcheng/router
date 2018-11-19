#include <iostream>
#include "point.h"
#include "point.cpp"
using namespace std;

int main()
{
    point a(4,5);
    cout<<"point a:"<<a.getx()<<","<<a.gety();
    point::showcount2();
    return 0;
}
