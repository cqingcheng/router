#include <iostream>
#include "lei.h"

using namespace std;
student::student(int x){
       int _id;
       cout<<"������ѧ�ţ�";
       cin>>_id;
       id=_id;
       int m=0;
       cout<<"���������䣺";
       cin>>m;
       age=m;
       string _name;
       cout<<"������������";
       cin>>_name;
       name=_name;
       if(x==1){xibie="English";}
        if(x==2){xibie="Mathematics department";}
        if(x==3){xibie="Computer Science";}
       float _gaoshu=0;
       cout<<"����������ɼ���";
       while(1){
            cin>>_gaoshu;
            if(_gaoshu<=100&&_gaoshu>=0){gaoshu=_gaoshu;break;}
             cout<<"�ɼ��쳣 �������룺";
       }
       float _yingyu=0;
       cout<<"������Ӣ��ɼ���";
       while(1){
            cin>>_yingyu;
            if(_yingyu<=100&&_yingyu>=0){yingyu=_yingyu;break;}
             cout<<"�ɼ��쳣 �������룺";
       }
       float _tiyu=0;
       cout<<"�����������ɼ���";
       while(1){
            cin>>_tiyu;
            if(_tiyu<=100&&_tiyu>=0){tiyu=_tiyu;break;}
             cout<<"�ɼ��쳣 �������룺";
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
   cout<<"ѧ��:"<<id;
   cout<<"     ����:"<<name;
   cout<<"     ����:"<<age;
   cout<<"     ϵ��:"<<xibie<<endl;
   cout<<"                                 �����ɼ�:"<<gaoshu;
   cout<<"    Ӣ��ɼ�"<<yingyu;
   cout<<"    �����ɼ���"<<tiyu;
}

float student::gpingjun(){
    float n=0;
    n=gaoshu+yingyu+tiyu;
    n/=3;
    return n;
}
