#include <iostream>
#include "lei1.h"

using namespace std;

yingyuxi::yingyuxi(float zhyy,float ku):student(1){
    zongheyingyu=zhyy;
   kouyu=ku;
}
void yingyuxi::show(){
    show1();
    cout<<"       综合英语成绩："<<zongheyingyu;
    cout<<"       口语成绩"<<kouyu<<endl;

}
void yingyuxi::chaxun(class yingyuxi *yhead){
    class yingyuxi *h;
    h=yhead;
    int n=0,m=0;
    cout<<"1.学号查找  2.姓名查找"<<endl;
    cout<<"请选择你要查找的方法:";
    cin>>n;
    while(n!=1&&n!=2){
        cout<<"选择错误，重新输入"<<endl;
        cin>>n;
    }
    if(n==1){
            int fid;
            cout<<"请输入学生学号：";
            cin>>fid;
            while(h!=NULL) {
                if(h->idfind(fid)){
                    h->show();
                    ++m;
                }
                h=h->next;
            }
    }
     if(n==2){
            string fname;
            cout<<"请输入学生姓名：";
            cin>>fname;
            while(h!=NULL) {
                if(h->namefind(fname)){
                    h->show();
                    ++m;
                }
                h=h->next;
            }
      if(m==0)cout<<"查无此人";

    }
}

void yingyuxi::add(class yingyuxi *yhead){
   class yingyuxi*h,*c;
   float zhyy,ku;
   cout<<"请输入综合英语成绩：";
    cin>>zhyy;
    cout<<"请输入口语成绩：";
    cin>>ku;
    c=new yingyuxi(zhyy,ku);
   h=yhead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void yingyuxi::shanchu(class yingyuxi *yhead){
    int nid;
    class yingyuxi *h,*pre;
    h=yhead;
    cout<<"请输入删除学生的学号:";
    cin>>nid;
    if(h->idfind(nid)){
        yhead=yhead->next;
        delete h;
    }
    else{
            while(h!=NULL){
                    pre=h;
                h=h->next;
                if(h->idfind(nid)){
                pre->next=h->next;
                delete h;
                 break;
                }
            }
    }
    cout<<"已删除学号为："<<nid<<"学生的信息"<<endl;
}

float yingyuxi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+zongheyingyu+kouyu;
     n/=5;
     return n;
}
