#ifndef GL_H_INCLUDED
#define GL_H_INCLUDED

#include "lei1.h"
#include "lei2.h"
#include "lei3.h"

class Guanli:virtual public yingyuxi,virtual public shuxuexi,virtual public jisuanjixi{
public:
    void Guanliluru();
    void chanxue();
    void add1();
    void shanchuxs();
    void gpx();
    void qpx();
    int Guanlisc();
    void show();
private:
    class yingyuxi *yhead;
    class shuxuexi *shead;
    class jisuanjixi *jhead;

};


#endif // GL_H_INCLUDED
