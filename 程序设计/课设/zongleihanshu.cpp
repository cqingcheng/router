#include <iostream>
#include "lei.h"

using namespace std;
student::student(int x){
       int _id;
       cout<<"请输入学号：";
       cin>>_id;
       id=_id;
       int m=0;
       cout<<"请输入年龄：";
       cin>>m;
       age=m;
       string _name;
       cout<<"请输入姓名：";
       cin>>_name;
       name=_name;
       if(x==1){xibie="English";}
        if(x==2){xibie="Mathematics department";}
        if(x==3){xibie="Computer Science";}
       float _gaoshu=0;
       cout<<"请输入高数成绩：";
       while(1){
            cin>>_gaoshu;
            if(_gaoshu<=100&&_gaoshu>=0){gaoshu=_gaoshu;break;}
             cout<<"成绩异常 重新输入：";
       }
       float _yingyu=0;
       cout<<"请输入英语成绩：";
       while(1){
            cin>>_yingyu;
            if(_yingyu<=100&&_yingyu>=0){yingyu=_yingyu;break;}
             cout<<"成绩异常 重新输入：";
       }
       float _tiyu=0;
       cout<<"请输入体育成绩：";
       while(1){
            cin>>_tiyu;
            if(_tiyu<=100&&_tiyu>=0){tiyu=_tiyu;break;}
             cout<<"成绩异常 重新输入：";
       }
}
int student::idfind(int fid){
           if(id==fid){return 1;}
           return 0;
}
int student::namefind(string fname){
       if(name==fname){return 1;}
       return 0;
}
void student::show1(){
   cout<<"学号:"<<id;
   cout<<"     姓名:"<<name;
   cout<<"     年龄:"<<age;
   cout<<"     系别:"<<xibie<<endl;
   cout<<"                                 高数成绩:"<<gaoshu;
   cout<<"    英语成绩"<<yingyu;
   cout<<"    体育成绩："<<tiyu;
}

float student::gpingjun(){
    float n=0;
    n=gaoshu+yingyu+tiyu;
    n/=3;
    return n;
}
