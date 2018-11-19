#ifndef LEI1_H_INCLUDED
#define LEI1_H_INCLUDED


class yingyuxi:virtual public student
{
   public:
       yingyuxi(){}
     yingyuxi(float zhyy,float ku);
     void chaxun(class yingyuxi *yhead);
     void show();
     class yingyuxi *next;
    void add(class yingyuxi *yhead);
    void shanchu(class yingyuxi *yhead);
    float qpingjun();
   private:
    float zongheyingyu;
    float kouyu;

};


#endif // LEI1_H_INCLUDED
