#include <iostream>
#include "lei3.h"
using namespace std;
jisuanjixi::jisuanjixi(int i):student(3){
       zucheng=0;
       tixi=0;
       huibian=0;
       cout<<"请输入计算机组成原理的成绩:";
       cin>>zucheng;
       cout<<"请输入计算机体系结构的成绩:";
       cin>>tixi;
       cout<<"请输入汇编语言成绩的成绩:";
       cin>>huibian;
}
void jisuanjixi::show(){
    show1();
    cout<<"     组成原理成绩："<<zucheng;
    cout<<"     体系结构成绩："<<tixi;
    cout<<"     汇编语言成绩："<<huibian<<endl;
}

void jisuanjixi::chaxun(class jisuanjixi *jhead){
    class jisuanjixi *h;
    h=jhead;
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

void jisuanjixi::add(class jisuanjixi *jhead){
   class jisuanjixi*h,*c;
       c=new jisuanjixi(0);
   h=jhead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void jisuanjixi::shanchu(class jisuanjixi *jhead){
    int nid;
    class jisuanjixi *h,*pre;
    h=jhead;
    cout<<"请输入删除学生的学号:";
    cin>>nid;
    if(h->idfind(nid)){
        jhead=jhead->next;
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

float jisuanjixi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+zucheng+tixi+huibian;
     n/=6;
     return n;
}
