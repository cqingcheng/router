#include <iostream>
#include <fstream>
#include<iomanip>
#include <stdlib.h>
#include <windows.h>
#include "lei.h"
#include "zongleihanshu.cpp"
#include "gl.h"
#include "gl.cpp"
#include "lei1.h"
#include "yingyuxi.cpp"
#include "lei2.h"
#include "shuxuexi.cpp"
#include "lei3.h"
#include "jisuanjixi.cpp"
using namespace std;
int mulu(class Guanli *a);

void kaishimulu(){
  cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<setw(40)<<"����������Ϣ"<<endl;
}
void mulu1(){
    cout<<"                              1.����ѧ����Ϣ"<<endl;
	cout<<"                              2.ɾ��ѧ����Ϣ"<<endl;
    cout<<"                              3.����Ŀ¼"<<endl;
}
void catalog1(class Guanli *a){
	int n=0;
	mulu1();
	cout<<"                         ��������Ҫ���еĲ���:";
	cin>>n;
    if(n==1){a->add1();catalog1(a);}
    if(n==2){a->shanchuxs();catalog1(a);}
    if(n==3){system("cls");mulu(a);}
    if(n<1||n>3){system("cls");catalog1(a);}
}
void mulu2(){
    cout<<endl;
    cout<<endl;
      cout<<"                              1.�������ɼ�����"<<endl;
      cout<<"                              2.���ܳɼ�����"<<endl;
	  cout<<"                              3.����Ŀ¼"<<endl;
}
void catalog2(class Guanli *a){
      int n=0;
	  mulu2();
	  cout<<"                         ��������Ҫ���еĲ���:";
	  cin>>n;
      if(n==1){a->gpx();catalog2(a);}
      if(n==2){a->qpx();catalog2(a);}
      if(n==3){system("cls");mulu(a);}
      if(n<1||n>3){system("cls");catalog2(a);}

}


int mulu(class Guanli *a){
    int n=0;
   cout<<endl;
   cout<<endl;
   cout<<"--------------------------------------ѧ���ɼ�����ϵͳ-----------------------------------------"<<endl;
   cout<<"                                       1.��Ϣ��ѯ"<<endl;
   cout<<"                                       2.��Ϣά��"<<endl;
   cout<<"                                       3.�ɼ�����"<<endl;
   cout<<"                                       4.�ɼ�Ŀ¼"<<endl;
   cout<<"                                       5.�˳�ϵͳ"<<endl;
   cout<<"------------------------------------------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"                         ��������Ҫ���еĲ���:";
   cin>>n;
   if(n==1){a->chanxue();mulu(a);}
   if(n==2){catalog1(a);}
   if(n==3){catalog2(a);}
   if(n==4){a->show();mulu(a);}
   if(n==5){cout<<"��������˳�";return 0;}
}

int main()
{
   int n=0;
   Guanli *a;
   system("cls");
   kaishimulu();
   Sleep(800);
   system("cls");
   a->Guanliluru();
   system("cls");
   mulu(a);
   a->Guanlisc();
   return 0;
}






