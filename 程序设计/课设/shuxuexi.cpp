#include <iostream>
#include "lei2.h"

using namespace std;
void shuxuexi::show(){
    show1();
    cout<<"       实变函数成绩:"<<shibian;
    cout<<"       泛函分析成绩："<<fanhan;
    cout<<"       微分几何成绩："<<weifen<<endl;
}


void shuxuexi::chaxun(class shuxuexi *shead){
    class shuxuexi *h;
    h=shead;
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


 void shuxuexi::add(class shuxuexi *shead){
   class shuxuexi*h,*c;
   float sbhs,fhfx,wfjh;

    cout<<"请输入实变函数的成绩:";
       cin>>sbhs;
       cout<<"请输入泛函分析的成绩:";
       cin>>fhfx;
       cout<<"请输入微分几何的成绩:";
       cin>>wfjh;
       c=new shuxuexi(sbhs,fhfx,wfjh);
   h=shead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void shuxuexi::shanchu(class shuxuexi *shead){
    int nid;
    class shuxuexi *h,*pre;
    h=shead;
    cout<<"请输入删除学生的学号:";
    cin>>nid;
    if(h->idfind(nid)){
        shead=shead->next;
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

float shuxuexi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+shibian+fanhan+weifen;
     n/=6;
     return n;

}
