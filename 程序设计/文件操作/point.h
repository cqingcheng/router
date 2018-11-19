#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class point{
public:
    point(int  x=0,int y=0):x(x),y(y){}
    point(const point &p);
    ~point(){count2--;}
    int getx()const{return x;}
    int gety()const{return y;}
    static void showcount2();
private:
    int x,y;
    static int count2;
};


#endif // POINT_H_INCLUDED
