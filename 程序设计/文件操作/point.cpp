#include "point.h"
#include <iostream>
using namespace std;

int point::count2=0;
void point::showcount2(){
   cout<<" object count="<<count2<<endl;

}
point::point(const point &p):x(p.x),y(p.y){
   count2++;
}
