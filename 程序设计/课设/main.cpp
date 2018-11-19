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
   cout<<setw(40)<<"请先输入信息"<<endl;
}
void mulu1(){
    cout<<"                              1.增加学生信息"<<endl;
	cout<<"                              2.删除学生信息"<<endl;
    cout<<"                              3.返回目录"<<endl;
}
void catalog1(class Guanli *a){
	int n=0;
	mulu1();
	cout<<"                         请输入你要进行的操作:";
	cin>>n;
    if(n==1){a->add1();catalog1(a);}
    if(n==2){a->shanchuxs();catalog1(a);}
    if(n==3){system("cls");mulu(a);}
    if(n<1||n>3){system("cls");catalog1(a);}
}
void mulu2(){
    cout<<endl;
    cout<<endl;
      cout<<"                              1.按公共成绩排序"<<endl;
      cout<<"                              2.按总成绩排序"<<endl;
	  cout<<"                              3.返回目录"<<endl;
}
void catalog2(class Guanli *a){
      int n=0;
	  mulu2();
	  cout<<"                         请输入你要进行的操作:";
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
   cout<<"--------------------------------------学生成绩管理系统-----------------------------------------"<<endl;
   cout<<"                                       1.信息查询"<<endl;
   cout<<"                                       2.信息维护"<<endl;
   cout<<"                                       3.成绩排序"<<endl;
   cout<<"                                       4.成绩目录"<<endl;
   cout<<"                                       5.退出系统"<<endl;
   cout<<"------------------------------------------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"                         请输入你要进行的操作:";
   cin>>n;
   if(n==1){a->chanxue();mulu(a);}
   if(n==2){catalog1(a);}
   if(n==3){catalog2(a);}
   if(n==4){a->show();mulu(a);}
   if(n==5){cout<<"按任意键退出";return 0;}
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






