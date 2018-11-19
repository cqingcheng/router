#ifndef GUANLI_H_INCLUDED
#define GUANLI_H_INCLUDED
using namespace std;
class student{
public:
        student(){}
        student(int x);
        int idfind(int fid);
        int namefind(string fname);
        void show1();
        float gpingjun();
        virtual void chaxun(){}
        virtual void add(){}
        virtual void shanchu(){}
private:
       int id;
       string name;
       int age;
       string xibie;
       float gaoshu;
       float yingyu;
       float tiyu;
};
#endif






